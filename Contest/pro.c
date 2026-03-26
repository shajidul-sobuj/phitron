/*
 * phonebook.c
 * Simplified Mobile Phonebook Application (C)
 *
 * Features:
 * - Store contacts (name, phone, email) in an array
 * - Add, display, search (by name or phone), update contacts
 * - Save/load contacts to/from a CSV file
 * - Simple text-based menu
 *
 * Build:
 *   gcc -o phonebook phonebook.c
 *
 * Usage:
 *   ./phonebook
 *
 * Notes:
 * - Basic input validation (non-empty name, phone digits, simple email check)
 * - CSV fields must not contain commas (simple restriction to keep parsing easy)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 1000
#define NAME_LEN 64
#define PHONE_LEN 32
#define EMAIL_LEN 64
#define FILENAME "contacts.csv"

/* Contact structure */
typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
} Contact;

/* Global contact list and count */
static Contact contacts[MAX_CONTACTS];
static int contact_count = 0;

/* Utility: trim newline and trailing spaces */
static void trim_newline(char *s) {
    size_t len = strlen(s);
    while (len > 0 && (s[len-1] == '\n' || s[len-1] == '\r')) {
        s[len-1] = '\0';
        len--;
    }
}

/* Utility: read a line from stdin safely */
static void read_line(const char *prompt, char *buf, size_t size) {
    if (prompt) {
        printf("%s", prompt);
        fflush(stdout);
    }
    if (fgets(buf, (int)size, stdin) == NULL) {
        /* EOF or error - clear the buffer */
        buf[0] = '\0';
        return;
    }
    trim_newline(buf);
}

/* Validation: simple phone check (digits, spaces, '+', '-', parentheses allowed) */
static int valid_phone(const char *p) {
    if (!p || p[0] == '\0') return 0;
    int digits = 0;
    for (const char *c = p; *c; ++c) {
        if (isdigit((unsigned char)*c)) digits++;
        else if (*c == '+' || *c == '-' || *c == ' ' || *c == '(' || *c == ')') continue;
        else return 0; /* invalid char */
    }
    return digits >= 5; /* require some digits */
}

/* Validation: simple email check (contains '@' and a dot after '@') */
static int valid_email(const char *e) {
    if (!e || e[0] == '\0') return 1; /* allow empty email */
    const char *at = strchr(e, '@');
    if (!at) return 0;
    const char *dot = strchr(at + 1, '.');
    if (!dot) return 0;
    return 1;
}

/* Convert string to lowercase copy for case-insensitive comparisons */
static void to_lower_copy(const char *src, char *dst, size_t dst_size) {
    size_t i;
    for (i = 0; i < dst_size - 1 && src[i]; ++i) {
        dst[i] = (char)tolower((unsigned char)src[i]);
    }
    dst[i] = '\0';
}

/* Add a new contact */
static void add_contact(void) {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list full (max %d).\n", MAX_CONTACTS);
        return;
    }

    Contact c;
    char buffer[256];

    /* Name (required, no commas) */
    while (1) {
        read_line("Enter name: ", buffer, sizeof(buffer));
        if (buffer[0] == '\0') {
            printf("Name cannot be empty. Please try again.\n");
            continue;
        }
        if (strchr(buffer, ',')) {
            printf("Commas are not allowed in name. Please remove commas.\n");
            continue;
        }
        strncpy(c.name, buffer, NAME_LEN-1);
        c.name[NAME_LEN-1] = '\0';
        break;
    }

    /* Phone (required, validated) */
    while (1) {
        read_line("Enter phone number: ", buffer, sizeof(buffer));
        if (!valid_phone(buffer)) {
            printf("Invalid phone. Use digits and optionally '+', '-', '(', ')', spaces. At least 5 digits required.\n");
            continue;
        }
        if (strchr(buffer, ',')) {
            printf("Commas are not allowed in phone. Please remove commas.\n");
            continue;
        }
        strncpy(c.phone, buffer, PHONE_LEN-1);
        c.phone[PHONE_LEN-1] = '\0';
        break;
    }

    /* Email (optional, simple validation) */
    while (1) {
        read_line("Enter email (optional): ", buffer, sizeof(buffer));
        if (strchr(buffer, ',')) {
            printf("Commas are not allowed in email. Please remove commas.\n");
            continue;
        }
        if (!valid_email(buffer)) {
            printf("Email looks invalid. Provide a valid email or leave blank.\n");
            continue;
        }
        strncpy(c.email, buffer, EMAIL_LEN-1);
        c.email[EMAIL_LEN-1] = '\0';
        break;
    }

    contacts[contact_count++] = c;
    printf("Contact added. Total contacts: %d\n", contact_count);
}

/* Display all contacts */
static void display_contacts(void) {
    if (contact_count == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("\n%-4s | %-30s | %-18s | %-30s\n", "No.", "Name", "Phone", "Email");
    printf("-----+--------------------------------+--------------------+--------------------------------\n");
    for (int i = 0; i < contact_count; ++i) {
        printf("%-4d | %-30s | %-18s | %-30s\n", i+1, contacts[i].name, contacts[i].phone,
               contacts[i].email[0] ? contacts[i].email : "-");
    }
    printf("\n");
}

/* Search contacts by name (substring, case-insensitive) or phone (substring) */
static void search_contacts(void) {
    char buffer[256];
    read_line("Search by (1) Name or (2) Phone? Enter 1 or 2: ", buffer, sizeof(buffer));
    if (buffer[0] == '1') {
        read_line("Enter name or part of name to search: ", buffer, sizeof(buffer));
        if (buffer[0] == '\0') {
            printf("Empty search string.\n");
            return;
        }
        char q_lower[256];
        to_lower_copy(buffer, q_lower, sizeof(q_lower));
        int found = 0;
        for (int i = 0; i < contact_count; ++i) {
            char name_lower[NAME_LEN];
            to_lower_copy(contacts[i].name, name_lower, sizeof(name_lower));
            if (strstr(name_lower, q_lower) != NULL) {
                if (!found) {
                    printf("\nMatches:\n");
                    printf("%-4s | %-30s | %-18s | %-30s\n", "No.", "Name", "Phone", "Email");
                    printf("-----+--------------------------------+--------------------+--------------------------------\n");
                }
                printf("%-4d | %-30s | %-18s | %-30s\n", i+1, contacts[i].name, contacts[i].phone,
                       contacts[i].email[0] ? contacts[i].email : "-");
                found++;
            }
        }
        if (!found) printf("No contacts matched the name query.\n");
    } else if (buffer[0] == '2') {
        read_line("Enter phone number or part of it to search: ", buffer, sizeof(buffer));
        if (buffer[0] == '\0') {
            printf("Empty search string.\n");
            return;
        }
        int found = 0;
        for (int i = 0; i < contact_count; ++i) {
            if (strstr(contacts[i].phone, buffer) != NULL) {
                if (!found) {
                    printf("\nMatches:\n");
                    printf("%-4s | %-30s | %-18s | %-30s\n", "No.", "Name", "Phone", "Email");
                    printf("-----+--------------------------------+--------------------+--------------------------------\n");
                }
                printf("%-4d | %-30s | %-18s | %-30s\n", i+1, contacts[i].name, contacts[i].phone,
                       contacts[i].email[0] ? contacts[i].email : "-");
                found++;
            }
        }
        if (!found) printf("No contacts matched the phone query.\n");
    } else {
        printf("Invalid option.\n");
    }
}

/* Update an existing contact */
static void update_contact(void) {
    if (contact_count == 0) {
        printf("No contacts to update.\n");
        return;
    }
    char buffer[256];
    display_contacts();
    read_line("Enter contact number to update (or 0 to cancel): ", buffer, sizeof(buffer));
    int idx = atoi(buffer);
    if (idx == 0) {
        printf("Update canceled.\n");
        return;
    }
    if (idx < 1 || idx > contact_count) {
        printf("Invalid contact number.\n");
        return;
    }
    Contact *c = &contacts[idx - 1];
    printf("Updating contact #%d: %s | %s | %s\n", idx, c->name, c->phone, c->email[0] ? c->email : "-");

    /* Update fields (enter to keep current) */
    read_line("Enter new name (leave blank to keep current): ", buffer, sizeof(buffer));
    if (buffer[0] != '\0') {
        if (strchr(buffer, ',')) {
            printf("Commas are not allowed in name. Skipping name update.\n");
        } else {
            strncpy(c->name, buffer, NAME_LEN-1);
            c->name[NAME_LEN-1] = '\0';
        }
    }

    while (1) {
        read_line("Enter new phone (leave blank to keep current): ", buffer, sizeof(buffer));
        if (buffer[0] == '\0') break; /* keep current */
        if (!valid_phone(buffer)) {
            printf("Invalid phone. Try again or leave blank to keep current.\n");
            continue;
        }
        if (strchr(buffer, ',')) {
            printf("Commas are not allowed in phone. Please remove commas.\n");
            continue;
        }
        strncpy(c->phone, buffer, PHONE_LEN-1);
        c->phone[PHONE_LEN-1] = '\0';
        break;
    }

    while (1) {
        read_line("Enter new email (leave blank to keep current / empty): ", buffer, sizeof(buffer));
        if (buffer[0] == '\0') break; /* keep current */
        if (strchr(buffer, ',')) {
            printf("Commas are not allowed in email. Please remove commas.\n");
            continue;
        }
        if (!valid_email(buffer)) {
            printf("Invalid email. Try again or leave blank to keep current.\n");
            continue;
        }
        strncpy(c->email, buffer, EMAIL_LEN-1);
        c->email[EMAIL_LEN-1] = '\0';
        break;
    }

    printf("Contact updated.\n");
}

/* Save contacts to a CSV file */
static void save_to_file(void) {
    FILE *f = fopen(FILENAME, "w");
    if (!f) {
        perror("Failed to open file for writing");
        return;
    }
    /* CSV header (optional) */
    fprintf(f, "name,phone,email\n");
    for (int i = 0; i < contact_count; ++i) {
        /* Note: fields should not contain commas */
        fprintf(f, "%s,%s,%s\n",
                contacts[i].name,
                contacts[i].phone,
                contacts[i].email);
    }
    fclose(f);
    printf("Saved %d contacts to %s\n", contact_count, FILENAME);
}

/* Load contacts from a CSV file */
static void load_from_file(void) {
    FILE *f = fopen(FILENAME, "r");
    if (!f) {
        printf("No saved contacts found (%s missing).\n", FILENAME);
        return;
    }
    char line[512];
    int loaded = 0;
    /* Read header line (if exists) */
    if (fgets(line, sizeof(line), f) == NULL) {
        fclose(f);
        printf("File is empty.\n");
        return;
    }
    trim_newline(line);
    /* If header contains "name" assume it's header and skip, otherwise process it */
    int is_header = 0;
    char *lower = strdup(line);
    if (!lower) lower = line;
    for (char *p = lower; *p; ++p) *p = (char)tolower((unsigned char)*p);
    if (strstr(lower, "name") && strstr(lower, "phone")) is_header = 1;
    if (lower != line) free(lower);

    if (!is_header) {
        /* process first line as data - fallthrough by seeking back start */
        rewind(f);
    }

    contact_count = 0;
    while (fgets(line, sizeof(line), f) && contact_count < MAX_CONTACTS) {
        trim_newline(line);
        /* Simple CSV parse: split by commas into three fields */
        char *p1 = line;
        char *p2 = strchr(p1, ',');
        if (!p2) continue;
        *p2 = '\0'; p2++;
        char *p3 = strchr(p2, ',');
        if (!p3) continue;
        *p3 = '\0'; p3++;

        /* Copy into struct, ensure lengths */
        strncpy(contacts[contact_count].name, p1, NAME_LEN-1);
        contacts[contact_count].name[NAME_LEN-1] = '\0';
        strncpy(contacts[contact_count].phone, p2, PHONE_LEN-1);
        contacts[contact_count].phone[PHONE_LEN-1] = '\0';
        strncpy(contacts[contact_count].email, p3, EMAIL_LEN-1);
        contacts[contact_count].email[EMAIL_LEN-1] = '\0';

        contact_count++;
        loaded++;
    }
    fclose(f);
    printf("Loaded %d contacts from %s\n", loaded, FILENAME);
}

/* Simple menu loop */
static void menu_loop(void) {
    char choice[16];
    while (1) {
        printf("\n=== Simple Phonebook ===\n");
        printf("1) Add contact\n");
        printf("2) Display all contacts\n");
        printf("3) Search contacts\n");
        printf("4) Update contact\n");
        printf("5) Save contacts to file (%s)\n", FILENAME);
        printf("6) Load contacts from file (%s)\n", FILENAME);
        printf("0) Exit\n");
        read_line("Choose an option: ", choice, sizeof(choice));
        if (choice[0] == '1') add_contact();
        else if (choice[0] == '2') display_contacts();
        else if (choice[0] == '3') search_contacts();
        else if (choice[0] == '4') update_contact();
        else if (choice[0] == '5') save_to_file();
        else if (choice[0] == '6') load_from_file();
        else if (choice[0] == '0') {
            printf("Goodbye.\n");
            break;
        } else {
            printf("Invalid option. Please choose from menu.\n");
        }
    }
}

/* Main */
int main(void) {
    /* Try load at start (non-fatal) */
    load_from_file();
    menu_loop();
    /* Optionally save on exit? Not automatically; user chooses Save menu option */
    return 0;
}
