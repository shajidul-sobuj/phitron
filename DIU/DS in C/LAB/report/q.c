#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    char name[50];
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear  = NULL;

void enqueue(int id, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (rear == NULL) {
        front = newNode;
        rear  = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Added: [%d] %s\n", id, name);
}

void dequeue() {
    if (front == NULL) {
        printf("No patient left in the queue.\n");
        return;
    }
    Node* temp = front;
    printf("Sent for treatment: [%d] %s\n", temp->id, temp->name);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void peek() {
    if (front == NULL) {
        printf("No patient left in the queue.\n");
        return;
    }
    printf("Next patient: [%d] %s\n", front->id, front->name);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node* curr = front;
    printf("Current queue: ");
    while (curr != NULL) {
        printf("[%d] %s", curr->id, curr->name);
        if (curr->next != NULL) printf(" -> ");
        curr = curr->next;
    }
    printf("\n");
}

void clearQueue() {
    while (front != NULL) {
        Node* temp = front;
        front = front->next;
        free(temp);
    }
    rear = NULL;
}

int main() {
    int extraPatients, treatCount, newPatients;
    int id;
    char name[50];

    printf("=== Hospital Patient Queue ===\n");
    printf("Preloaded patient data added from code.\n");
    enqueue(100, "Sobuj");

    printf("\nHow many more patients to register now? ");
    if (scanf("%d", &extraPatients) != 1) {
        clearQueue();
        return 0;
    }

    for (int i = 0; i < extraPatients; i++) {
        printf("Enter patient %d (id name): ", i + 1);
        if (scanf("%d %49s", &id, name) != 2) {
            clearQueue();
            return 0;
        }
        enqueue(id, name);
    }

    printf("\nQueue status after registration:\n");
    display();

    printf("\nHow many patients to send for treatment? ");
    if (scanf("%d", &treatCount) != 1) {
        clearQueue();
        return 0;
    }

    for (int i = 0; i < treatCount; i++) {
        dequeue();
    }

    printf("\nHow many new patients arrived? ");
    if (scanf("%d", &newPatients) != 1) {
        clearQueue();
        return 0;
    }

    for (int i = 0; i < newPatients; i++) {
        printf("Enter new patient %d (id name): ", i + 1);
        if (scanf("%d %49s", &id, name) != 2) {
            clearQueue();
            return 0;
        }
        enqueue(id, name);
    }

    printf("\nFinal queue:\n");
    display();
    peek();

    clearQueue();

    return 0;
}