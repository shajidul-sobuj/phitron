#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
    struct node *pre;
}Node;

void insert_nodes(Node **head, Node **tail, int val)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->val = val;
    newnode->next = NULL;
    newnode->pre = NULL;

    if (*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
        return;
    }

    (*tail)->next = newnode;
    newnode->pre = *tail;
    *tail = newnode;
}

void printing_forword(Node *head)
{
    Node *temp = head;
    while(temp->next!=NULL)
    {
        printf("%d ->",temp->val);
        temp = temp->next;
    }
    printf("%d\n",temp->val);
}

void printing_backword(Node *tail)
{
    Node *temp = tail;
    while(temp->pre!=NULL)
    {
        printf("%d ->",temp->val);
        temp = temp->pre;
    }
    printf("%d\n",temp->val);
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int x;
    while(scanf("%d",&x))
    {
        if (x==-1) break;
        insert_nodes(&head, &tail, x);
    }
    printf("Doubly linked list forword ptinting: ");
    printing_forword(head);
    printf("Doubly linked list backword ptinting: ");
    printing_backword(tail);

    return 0;
}