#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 500
#define FILENAME "phonebook_data.txt"

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

Contact phonebook[MAX_CONTACTS];
int contactCount = 0;

void loadFromFile();
void saveToFile();
void addContact();
void displayContacts();
void searchContact();
void updateContact();
void clearBuffer();
void removeNewline(char str[]);

int main() {
    int choice;

    loadFromFile();

    while (1) {
        printf("\n------------------------------\n");
        printf(" DIU STUDENT PHONEBOOK SYSTEM\n");
        printf("------------------------------\n");
        printf("1. Add Contact\n");
        printf("2. Show All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Save and Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        if (choice == 1) addContact();
        else if (choice == 2) displayContacts();
        else if (choice == 3) searchContact();
        else if (choice == 4) updateContact();
        else if (choice == 5) {
            saveToFile();
            printf("Data saved. Program closed.\n");
            break;
        }
        else {
            printf("Wrong choice\n");
        }
    }

    return 0;
}

void removeNewline(char str[]) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

void clearBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phonebook full\n");
        return;
    }

    printf("\nName: ");
    fgets(phonebook[contactCount].name, 50, stdin);
    removeNewline(phonebook[contactCount].name);

    printf("Phone: ");
    fgets(phonebook[contactCount].phone, 20, stdin);
    removeNewline(phonebook[contactCount].phone);

    printf("Email: ");
    fgets(phonebook[contactCount].email, 50, stdin);
    removeNewline(phonebook[contactCount].email);

    contactCount++;
    printf("Contact added\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts found\n");
        return;
    }

    printf("\nID   Name                 Phone           Email\n");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < contactCount; i++) {
        printf("%-4d %-20s %-15s %-25s\n",
               i + 1,
               phonebook[i].name,
               phonebook[i].phone,
               phonebook[i].email);
    }
}

void searchContact() {
    char key[50];
    int found = 0;

    printf("\nSearch by name or phone: ");
    fgets(key, 50, stdin);
    removeNewline(key);

    for (int i = 0; i < contactCount; i++) {
        if (strstr(phonebook[i].name, key) || strstr(phonebook[i].phone, key)) {
            printf("%s | %s | %s\n",
                   phonebook[i].name,
                   phonebook[i].phone,
                   phonebook[i].email);
            found = 1;
        }
    }

    if (!found)
        printf("No match found\n");
}

void updateContact() {
    char name[50];
    int index = -1;

    printf("\nEnter name to update: ");
    fgets(name, 50, stdin);
    removeNewline(name);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Contact not found\n");
        return;
    }

    printf("New phone: ");
    fgets(phonebook[index].phone, 20, stdin);
    removeNewline(phonebook[index].phone);

    printf("New email: ");
    fgets(phonebook[index].email, 50, stdin);
    removeNewline(phonebook[index].email);

    printf("Contact updated\n");
}

void saveToFile() {
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) return;

    fprintf(fp, "%d\n", contactCount);
    for (int i = 0; i < contactCount; i++) {
        fprintf(fp, "%s\n%s\n%s\n",
                phonebook[i].name,
                phonebook[i].phone,
                phonebook[i].email);
    }

    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) return;

    fscanf(fp, "%d\n", &contactCount);

    for (int i = 0; i < contactCount; i++) {
        fgets(phonebook[i].name, 50, fp);
        removeNewline(phonebook[i].name);

        fgets(phonebook[i].phone, 20, fp);
        removeNewline(phonebook[i].phone);

        fgets(phonebook[i].email, 50, fp);
        removeNewline(phonebook[i].email);
    }

    fclose(fp);
}
