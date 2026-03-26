/*
 * server.c
 * Simple HTTP server + phonebook backend (single-threaded)
 *
 * Features:
 * - Serves static files from current directory (index.html, styles.css, app.js)
 * - Endpoints:
 *     GET  /api/contacts        -> JSON array of contacts
 *     POST /api/add             -> add contact (form-urlencoded or JSON)
 *     POST /api/update          -> update contact by index (json)
 *     POST /api/save            -> save contacts to contacts.csv
 *     POST /api/load            -> load contacts from contacts.csv
 * - Contacts stored in-memory and optionally persisted to CSV
 *
 * Build:
 *   gcc -o server server.c
 *
 * Run:
 *   ./server
 *   then open http://localhost:8000 in browser
 *
 * Note: Minimal error handling; intended for demonstration / learning.
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8000
#define BACKLOG 10
#define BUF_SIZE 8192

#define MAX_CONTACTS 1000
#define NAME_LEN 64
#define PHONE_LEN 32
#define EMAIL_LEN 64
#define CSV_FILE "contacts.csv"

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
} Contact;

static Contact contacts[MAX_CONTACTS];
static int contact_count = 0;

/* Utility functions */
static void trim_newline(char *s) {
    size_t n = strlen(s);
    while (n > 0 && (s[n-1] == '\n' || s[n-1] == '\r')) { s[n-1] = '\0'; n--; }
}

static void send_response(int client, const char *status, const char *ctype, const char *body) {
    char header[1024];
    int len = body ? (int)strlen(body) : 0;
    snprintf(header, sizeof(header),
             "HTTP/1.1 %s\r\n"
             "Content-Type: %s\r\n"
             "Content-Length: %d\r\n"
             "Connection: close\r\n"
             "\r\n", status, ctype, len);
    send(client, header, strlen(header), 0);
    if (len) send(client, body, len, 0);
}

static void url_decode(char *dst, const char *src) {
    // very small url-decode for form parsing
    for (; *src; src++) {
        if (*src == '+') *dst++ = ' ';
        else if (*src == '%' && isxdigit((unsigned char)src[1]) && isxdigit((unsigned char)src[2])) {
            char hex[3] = { src[1], src[2], 0 };
            *dst++ = (char)strtol(hex, NULL, 16);
            src += 2;
        } else {
            *dst++ = *src;
        }
    }
    *dst = '\0';
}

/* Simple CSV save/load */
static void save_to_csv(void) {
    FILE *f = fopen(CSV_FILE, "w");
    if (!f) return;
    fprintf(f, "name,phone,email\n");
    for (int i = 0; i < contact_count; ++i) {
        fprintf(f, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
    fclose(f);
}

static int load_from_csv(void) {
    FILE *f = fopen(CSV_FILE, "r");
    if (!f) return 0;
    char line[512];
    // skip header
    if (!fgets(line, sizeof(line), f)) { fclose(f); return 0; }
    contact_count = 0;
    while (fgets(line, sizeof(line), f) && contact_count < MAX_CONTACTS) {
        trim_newline(line);
        char *p = line;
        char *f1 = p;
        char *f2 = strchr(p, ',');
        if (!f2) continue;
        *f2 = '\0'; p = f2 + 1;
        char *f3 = strchr(p, ',');
        if (!f3) continue;
        *f3 = '\0'; // p points to phone, f3+1 is email
        strncpy(contacts[contact_count].name, f1, NAME_LEN-1); contacts[contact_count].name[NAME_LEN-1]='\0';
        strncpy(contacts[contact_count].phone, p, PHONE_LEN-1); contacts[contact_count].phone[PHONE_LEN-1]='\0';
        strncpy(contacts[contact_count].email, f3+1, EMAIL_LEN-1); contacts[contact_count].email[EMAIL_LEN-1]='\0';
        contact_count++;
    }
    fclose(f);
    return 1;
}

/* Build JSON array of contacts into dynamically allocated string (caller must free) */
/* helper: ensure `out` has capacity for `need` more bytes (not including terminating NUL).
   returns 1 on success, 0 on allocation failure. */
static int ensure_capacity(char **outp, size_t *capp, size_t used, size_t need) {
    if (used + need + 1 <= *capp) return 1;
    size_t newcap = *capp ? *capp : 1024;
    while (used + need + 1 > newcap) newcap *= 2;
    char *tmp = realloc(*outp, newcap);
    if (!tmp) return 0;
    *outp = tmp;
    *capp = newcap;
    return 1;
}

/* append raw string, resizing if necessary */
static int append_raw(char **outp, size_t *usedp, size_t *capp, const char *s) {
    size_t sl = strlen(s);
    if (!ensure_capacity(outp, capp, *usedp, sl)) return 0;
    memcpy(*outp + *usedp, s, sl);
    *usedp += sl;
    (*outp)[*usedp] = '\0';
    return 1;
}

/* append JSON-escaped string */
static int append_escaped(char **outp, size_t *usedp, size_t *capp, const char *s) {
    for (const unsigned char *p = (const unsigned char*)s; *p; ++p) {
        char esc[2]; size_t el = 1;
        if (*p == '"') { esc[0] = '\\'; esc[1] = '"'; el = 2; }
        else if (*p == '\\') { esc[0] = '\\'; esc[1] = '\\'; el = 2; }
        else if (*p == '\n') { esc[0] = '\\'; esc[1] = 'n'; el = 2; }
        else if (*p == '\r') { esc[0] = '\\'; esc[1] = 'r'; el = 2; }
        else if (*p == '\t') { esc[0] = '\\'; esc[1] = 't'; el = 2; }
        else { esc[0] = *p; el = 1; }
        if (!ensure_capacity(outp, capp, *usedp, el)) return 0;
        if (el == 1) { (*outp)[(*usedp)++] = esc[0]; }
        else { (*outp)[(*usedp)++] = esc[0]; (*outp)[(*usedp)++] = esc[1]; }
        (*outp)[*usedp] = '\0';
    }
    return 1;
}

static char *contacts_to_json(void) {
    size_t cap = 4096;
    char *out = malloc(cap);
    if (!out) return NULL;
    size_t used = 0;
    out[0] = '\0';

    if (!append_raw(&out, &used, &cap, "[")) { free(out); return NULL; }
    for (int i = 0; i < contact_count; ++i) {
        if (i) { if (!append_raw(&out, &used, &cap, ",")) { free(out); return NULL; } }
        if (!append_raw(&out, &used, &cap, "{\"index\":")) { free(out); return NULL; }
        char num[32]; snprintf(num, sizeof(num), "%d", i);
        if (!append_raw(&out, &used, &cap, num)) { free(out); return NULL; }
        if (!append_raw(&out, &used, &cap, ",\"name\":\"")) { free(out); return NULL; }
        if (!append_escaped(&out, &used, &cap, contacts[i].name)) { free(out); return NULL; }
        if (!append_raw(&out, &used, &cap, "\"")) { free(out); return NULL; }

        if (!append_raw(&out, &used, &cap, ",\"phone\":\"")) { free(out); return NULL; }
        if (!append_escaped(&out, &used, &cap, contacts[i].phone)) { free(out); return NULL; }
        if (!append_raw(&out, &used, &cap, "\"")) { free(out); return NULL; }

        if (!append_raw(&out, &used, &cap, ",\"email\":\"")) { free(out); return NULL; }
        if (!append_escaped(&out, &used, &cap, contacts[i].email)) { free(out); return NULL; }
        if (!append_raw(&out, &used, &cap, "\"}")) { free(out); return NULL; }
    }
    if (!append_raw(&out, &used, &cap, "]")) { free(out); return NULL; }
    return out;
}

/* minimal helper: serve a file from cwd */
static int serve_file(int client, const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) return 0;
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buf = malloc(sz + 1);
    if (!buf) { fclose(f); return 0; }
    fread(buf, 1, sz, f);
    buf[sz] = '\0';
    fclose(f);
    // determine content-type
    const char *ctype = "text/plain";
    if (strstr(path, ".html")) ctype = "text/html";
    else if (strstr(path, ".css")) ctype = "text/css";
    else if (strstr(path, ".js")) ctype = "application/javascript";
    else if (strstr(path, ".json")) ctype = "application/json";

    send_response(client, "200 OK", ctype, buf);
    free(buf);
    return 1;
}

/* parse form-urlencoded body into name/phone/email; returns 1 on success */
static int parse_form_urlencoded(const char *body, char *name, size_t nlen,
                                 char *phone, size_t plen, char *email, size_t elen) {
    // body like: name=Alice+Smith&phone=12345&email=a%40b.com
    char *dup = strdup(body);
    if (!dup) return 0;
    char *p = dup;
    char *token;
    while ((token = strsep(&p, "&")) != NULL) {
        char *eq = strchr(token, '=');
        if (!eq) continue;
        *eq = '\0';
        const char *k = token;
        const char *v = eq + 1;
        char decoded[256];
        url_decode(decoded, v);
        if (strcmp(k, "name") == 0) snprintf(name, nlen, "%s", decoded);
        else if (strcmp(k, "phone") == 0) snprintf(phone, plen, "%s", decoded);
        else if (strcmp(k, "email") == 0) snprintf(email, elen, "%s", decoded);
    }
    free(dup);
    return 1;
}

/* Basic request handler */
static void handle_client(int client) {
    char buf[BUF_SIZE];
    ssize_t r = recv(client, buf, sizeof(buf)-1, 0);
    if (r <= 0) { close(client); return; }
    buf[r] = '\0';

    // parse request line
    char method[16], path[256];
    if (sscanf(buf, "%15s %255s", method, path) != 2) {
        send_response(client, "400 Bad Request", "text/plain", "Bad Request");
        close(client);
        return;
    }

    // If path is "/" serve index.html
    if (strcmp(method, "GET") == 0) {
        if (strcmp(path, "/") == 0) {
            if (!serve_file(client, "index.html")) send_response(client, "404 Not Found", "text/plain", "index.html not found");
            close(client);
            return;
        }
        // serve static files if present (strip leading '/')
        if (path[0] == '/') {
            char pth[512];
            /* serve from current directory - skip leading '/' */
            snprintf(pth, sizeof(pth), "%s", path + 1);
            if (serve_file(client, pth)) { close(client); return; }
        }
        // API GET endpoints
        if (strcmp(path, "/api/contacts") == 0) {
            char *json = contacts_to_json();
            if (!json) send_response(client, "500 Internal Server Error", "application/json", "[]");
            else {
                send_response(client, "200 OK", "application/json", json);
                free(json);
            }
            close(client);
            return;
        }
        // if not matched
        send_response(client, "404 Not Found", "text/plain", "Not found");
        close(client);
        return;
    } else if (strcmp(method, "POST") == 0) {
        // find headers and body
        char *body = strstr(buf, "\r\n\r\n");
        if (!body) {
            send_response(client, "400 Bad Request", "text/plain", "Missing body");
            close(client);
            return;
        }
        body += 4; // start of body
        // read Content-Length header to ensure full body — simplistic: assume we got it all
        if (strcmp(path, "/api/add") == 0) {
            char name[NAME_LEN] = ""; char phone[PHONE_LEN] = ""; char email[EMAIL_LEN] = "";
            // check content-type if JSON or form
            if (strstr(buf, "application/x-www-form-urlencoded")) {
                parse_form_urlencoded(body, name, sizeof(name), phone, sizeof(phone), email, sizeof(email));
            } else if (strstr(buf, "application/json")) {
                // extremely simple json parsing: look for "name":"...", "phone":"...", "email":"..."
                char *p;
                if ((p = strstr(body, "\"name\"")) && (p = strchr(p, ':'))) {
                    p++;
                    while (*p && (*p==' '||*p=='\"')) { if (*p=='\"') { p++; break;} else p++; }
                    char tmp[128]; int i=0;
                    while (*p && *p!='\"' && i < (int)sizeof(tmp)-1) tmp[i++]=*p++;
                    tmp[i]=0; snprintf(name, sizeof(name), "%s", tmp);
                }
                if ((p = strstr(body, "\"phone\"")) && (p = strchr(p, ':'))) {
                    p++;
                    while (*p && (*p==' '||*p=='\"')) { if (*p=='\"') { p++; break;} else p++; }
                    char tmp[64]; int i=0;
                    while (*p && *p!='\"' && i < (int)sizeof(tmp)-1) tmp[i++]=*p++;
                    tmp[i]=0; snprintf(phone, sizeof(phone), "%s", tmp);
                }
                if ((p = strstr(body, "\"email\"")) && (p = strchr(p, ':'))) {
                    p++;
                    while (*p && (*p==' '||*p=='\"')) { if (*p=='\"') { p++; break;} else p++; }
                    char tmp[128]; int i=0;
                    while (*p && *p!='\"' && i < (int)sizeof(tmp)-1) tmp[i++]=*p++;
                    tmp[i]=0; snprintf(email, sizeof(email), "%s", tmp);
                }
            } else {
                // fallback try form parsing
                parse_form_urlencoded(body, name, sizeof(name), phone, sizeof(phone), email, sizeof(email));
            }

            // basic validation
            if (name[0] == '\0' || phone[0] == '\0') {
                send_response(client, "400 Bad Request", "text/plain", "Name and phone required");
                close(client); return;
            }
            if (contact_count < MAX_CONTACTS) {
                snprintf(contacts[contact_count].name, NAME_LEN, "%s", name);
                snprintf(contacts[contact_count].phone, PHONE_LEN, "%s", phone);
                snprintf(contacts[contact_count].email, EMAIL_LEN, "%s", email);
                contact_count++;
                send_response(client, "200 OK", "text/plain", "Contact added");
            } else {
                send_response(client, "500 Internal Server Error", "text/plain", "Storage full");
            }
            close(client); return;
        } else if (strcmp(path, "/api/save") == 0) {
            save_to_csv();
            send_response(client, "200 OK", "text/plain", "Saved");
            close(client); return;
        } else if (strcmp(path, "/api/load") == 0) {
            int ok = load_from_csv();
            if (ok) send_response(client, "200 OK", "text/plain", "Loaded");
            else send_response(client, "404 Not Found", "text/plain", "contacts.csv not found");
            close(client); return;
        } else if (strcmp(path, "/api/update") == 0) {
            // expects json: {"index":N,"name":"...","phone":"...","email":"..."}
            int idx = -1; char name[NAME_LEN] = ""; char phone[PHONE_LEN] = ""; char email[EMAIL_LEN] = "";
            char *p;
            if ((p = strstr(body, "\"index\"")) && (p = strchr(p, ':'))) {
                idx = atoi(p+1);
            }
            if (idx < 0 || idx >= contact_count) {
                send_response(client, "400 Bad Request", "text/plain", "Invalid index");
                close(client); return;
            }
            if ((p = strstr(body, "\"name\"")) && (p = strchr(p, ':'))) {
                p++; while (*p && (*p==' '||*p=='\"')) { if (*p=='\"') { p++; break;} else p++; }
                char tmp[128]; int i=0; while (*p && *p!='"' && i < (int)sizeof(tmp)-1) tmp[i++]=*p++; tmp[i]=0; snprintf(name, sizeof(name), "%s", tmp);
            }
            if ((p = strstr(body, "\"phone\"")) && (p = strchr(p, ':'))) {
                p++; while (*p && (*p==' '||*p=='\"')) { if (*p=='\"') { p++; break;} else p++; }
                char tmp[64]; int i=0; while (*p && *p!='"' && i < (int)sizeof(tmp)-1) tmp[i++]=*p++; tmp[i]=0; snprintf(phone, sizeof(phone), "%s", tmp);
            }
            if ((p = strstr(body, "\"email\"")) && (p = strchr(p, ':'))) {
                p++; while (*p && (*p==' '||*p=='\"')) { if (*p=='\"') { p++; break;} else p++; }
                char tmp[128]; int i=0; while (*p && *p!='"' && i < (int)sizeof(tmp)-1) tmp[i++]=*p++; tmp[i]=0; snprintf(email, sizeof(email), "%s", tmp);
            }
            if (name[0]) snprintf(contacts[idx].name, NAME_LEN, "%s", name);
            if (phone[0]) snprintf(contacts[idx].phone, PHONE_LEN, "%s", phone);
            if (email[0]) snprintf(contacts[idx].email, EMAIL_LEN, "%s", email);
            send_response(client, "200 OK", "text/plain", "Updated");
            close(client); return;
        }

        send_response(client, "404 Not Found", "text/plain", "API endpoint not found");
        close(client);
        return;
    } else {
        send_response(client, "405 Method Not Allowed", "text/plain", "Method not allowed");
        close(client);
        return;
    }
}

int main(void) {
    int sockfd, newfd;
    struct sockaddr_in addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) { perror("socket"); exit(1); }
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) { perror("bind"); exit(1); }
    if (listen(sockfd, BACKLOG) < 0) { perror("listen"); exit(1); }

    printf("Server running on http://localhost:%d\n", PORT);
    // Try to load existing contacts (non-fatal)
    load_from_csv();

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        newfd = accept(sockfd, (struct sockaddr *)&client_addr, &len);
        if (newfd < 0) { perror("accept"); continue; }
        handle_client(newfd);
    }
    close(sockfd);
    return 0;
}
