#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
}Node;

void printing(Node *head)
{
    Node *temp = head;
    while(temp->next!=NULL)
    {
        printf("%d -->",temp->val);
        temp = temp->next;
    }
    printf("%d",temp->val);
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node* a = NULL;
    Node* b = NULL;

    head = malloc(sizeof(Node));
    tail = malloc(sizeof(Node));
    a = malloc(sizeof(Node));
    b = malloc(sizeof(Node));

    head->next = a;
    a->next = b;
    b->next = tail;
    tail->next = NULL;


    head->val = 20;
    a->val = 23;
    b->val = 27;
    tail->val = 30;
    
    printing(head);
    return 0;
}