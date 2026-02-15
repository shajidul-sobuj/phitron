#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
}Node;

void insert_val(Node **head, Node **tail, int val)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->val = val;
    newnode->next = NULL;

    if (*head == NULL) 
    {
        *head = newnode;
        *tail = newnode;
        return;
    }
    (*tail)->next = newnode;
    *tail = newnode;

}

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
    int x;
    while(scanf("%d",&x))
    {
        if (x==-1) break;
        insert_val(&head,&tail,x);
    }
    printing(head);
    return 0;
}