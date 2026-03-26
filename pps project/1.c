#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 500
#define FILENAME "phonebook_data.txt"

// 1. Define Structure
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// Global variables
Contact phonebook[MAX_CONTACTS];
int contactCount = 0;

// Function Prototypes
void loadFromFile();
void saveToFile();
void addContact();
void displayContacts();
void searchContact();
void updateContact();
void clearInputBuffer();
void removeNewline(char* str);

int main() {
    int choice;
    
    // Load existing data immediately when program starts
    loadFromFile();

    do {
        printf("\n====================================\n");
        printf("   DIU STUDENT PHONEBOOK SYSTEM\n");
        printf("====================================\n");
        printf("1. Add New Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Save & Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            // Handle non-integer input to prevent infinite loops
            printf("\n[!] Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue; 
        }
        clearInputBuffer(); // Consume the newline left by scanf

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: updateContact(); break;
            case 5: 
                saveToFile();
                printf("\n[SUCCESS] Data saved. Exiting... Goodbye!\n");
                break;
            default: 
                printf("\n[!] Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// --- Implementation Functions ---

// Helper to remove the '\n' character added by fgets
void removeNewline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Helper to clear stdin buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("\n[!] Memory full! Cannot add more contacts.\n");
        return;
    }

    printf("\n--- Add New Contact ---\n");
    
    printf("Enter Name: ");
    fgets(phonebook[contactCount].name, 50, stdin);
    removeNewline(phonebook[contactCount].name);

    printf("Enter Phone: ");
    fgets(phonebook[contactCount].phone, 20, stdin);
    removeNewline(phonebook[contactCount].phone);

    printf("Enter Email: ");
    fgets(phonebook[contactCount].email, 50, stdin);
    removeNewline(phonebook[contactCount].email);

    contactCount++;
    printf("\n[SUCCESS] Contact added successfully!\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("\n[INFO] Phonebook is empty.\n");
        return;
    }

    printf("\n--- Contact List (%d) ---\n", contactCount);
    printf("%-5s %-20s %-15s %-25s\n", "ID", "Name", "Phone", "Email");
    printf("------------------------------------------------------------------\n");
    
    for (int i = 0; i < contactCount; i++) {
        printf("%-5d %-20s %-15s %-25s\n", 
               i + 1, 
               phonebook[i].name, 
               phonebook[i].phone, 
               phonebook[i].email);
    }
}

void searchContact() {
    char query[50];
    int found = 0;

    printf("\n--- Search Contact ---\n");
    printf("Enter Name or Phone to search: ");
    fgets(query, 50, stdin);
    removeNewline(query);

    printf("\nSearch Results:\n");
    for (int i = 0; i < contactCount; i++) {
        // strcasecmp is non-standard in strict ANSI C, using strstr for partial match
        // or stricmp depending on compiler. For strict C, we use strcmp or custom helper.
        // Here we use strstr to find if the query exists inside the name or phone.
        if (strstr(phonebook[i].name, query) != NULL || strstr(phonebook[i].phone, query) != NULL) {
            printf("Found: %s | %s | %s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("[!] No contact found matching '%s'.\n", query);
    }
}

void updateContact() {
    char query[50];
    int foundIndex = -1;

    printf("\n--- Update Contact ---\n");
    printf("Enter exact Name of the contact to update: ");
    fgets(query, 50, stdin);
    removeNewline(query);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, query) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("\nContact Found: %s\n", phonebook[foundIndex].name);
        printf("Enter New Phone: ");
        fgets(phonebook[foundIndex].phone, 20, stdin);
        removeNewline(phonebook[foundIndex].phone);

        printf("Enter New Email: ");
        fgets(phonebook[foundIndex].email, 50, stdin);
        removeNewline(phonebook[foundIndex].email);

        printf("\n[SUCCESS] Contact updated successfully.\n");
    } else {
        printf("\n[!] Contact not found.\n");
    }
}

void saveToFile() {
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("\n[ERROR] Could not open file for writing.\n");
        return;
    }

    // Saving count first makes loading easier
    fprintf(fp, "%d\n", contactCount);
    for (int i = 0; i < contactCount; i++) {
        // Using CSV style formatting for safety (Name,Phone,Email)
        fprintf(fp, "%s\n%s\n%s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
    }
    
    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("[INFO] No previous data found. Starting fresh.\n");
        return;
    }

    if (fscanf(fp, "%d", &contactCount) != 1) {
        contactCount = 0;
        fclose(fp);
        return;
    }
    
    // Consume newline after reading count
    char temp;
    fscanf(fp, "%c", &temp); 

    for (int i = 0; i < contactCount; i++) {
        fgets(phonebook[i].name, 50, fp);
        removeNewline(phonebook[i].name);
        
        fgets(phonebook[i].phone, 20, fp);
        removeNewline(phonebook[i].phone);
        
        fgets(phonebook[i].email, 50, fp);
        removeNewline(phonebook[i].email);
    }

    fclose(fp);
    printf("[SUCCESS] Loaded %d contacts from file.\n", contactCount);
}