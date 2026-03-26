#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int roll;
    char name[50];
    float cg;
    struct node* next;
}Node;

void printing(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        printf("Roll: %d, Name: %s, CGPA: %.2f\n",temp->roll,temp->name,temp->cg);
        temp = temp->next;
    }
}

// ans of Q no 2(a)
void print_from_back(Node* head)
{
    if (head == NULL)
    {
        return;
    }
    print_from_back(head->next);
    printf("Roll: %d, Name: %s, CGPA: %.2f\n",head->roll,head->name,head->cg);
}

// ans of Q no 2(b)
void insert_beginning(Node **head)
{
    Node* newnode = NULL;
    newnode = malloc(sizeof(Node));
    newnode->roll = 101;
    strcpy(newnode->name,"Maruf");
    newnode->cg = 3.56;
    newnode->next = *head;
    (*head) = newnode;
    return;
}

// ans of Q no 2(c)
void delete_last(Node* head,Node **tail)
{
    Node* deletenode = *tail;
    while(head->next->next!=NULL)
    {
        head = head->next;
    }
    head->next = NULL;
    *tail = head;
    free(deletenode);
}

int main()
{
    Node* head = NULL;
    Node* a = NULL;
    Node* tail = NULL;

    head = malloc(sizeof(Node));
    a = malloc(sizeof(Node));
    tail = malloc(sizeof(Node));

    head->roll = 102;
    strcpy(head->name,"Sobuj");
    head->cg = 3.25;

    a->roll = 105;
    strcpy(a->name,"Sajid");
    a->cg = 3.50;

    tail->roll = 109;
    strcpy(tail->name,"Akash");
    tail->cg = 2.75;

    head->next = a;
    a->next = tail;
    tail->next = NULL;

    printf("Printing form Backend: \n");
    print_from_back(head);

    printf("After Insert at Beginning: \n");
    insert_beginning(&head);
    printing(head);

    printf("After Delete Last student: \n");
    delete_last(head, &tail);
    printing(head);
    return 0;
}