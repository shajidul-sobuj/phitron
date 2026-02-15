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

void insert_at_head(Node **head, int val)
{
    Node *newnode = NULL;
    newnode = malloc(sizeof(Node));
    newnode->next = *head;
    (*head)->pre = newnode;
    newnode->pre = NULL;
    newnode->val = val;
    *head = newnode;
}

void insert_at_tail(Node **tail, int val)
{
    Node *newnode = NULL;
    newnode = malloc(sizeof(Node));
    newnode->val = val;
    newnode->next = NULL;
    newnode->pre = *tail;
    (*tail)->next = newnode;
    *tail = newnode;
}

void insert_at_any(Node *head, int val, int idx)
{
    Node *newnode = NULL;
    newnode = malloc(sizeof(Node));
    newnode->val = val;
    Node* temp = head;
    for (int i=0;i<idx-1;i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->pre = temp->next->pre;
    temp->next = newnode;
    newnode->next->pre = newnode;
}

void delete_at_head(Node **head)
{
    Node *deletenode = *head;
    (*head) = (*head)->next;
    (*head)->pre = NULL;
    free(deletenode);
}

void delete_at_tail(Node **tail)
{
    Node *deletenode = *tail;
    *tail = (*tail)->pre;
    (*tail)->next = NULL;
    free(deletenode);
}

void delete_at_any(Node *head, int idx)
{
    Node* temp = head;
    for (int i=0;i<idx-1;i++)
    {
        temp = temp->next;
    }
    Node *deletenode = temp->next;
    temp->next = deletenode->next;
    temp->next->pre = deletenode->pre;
    free(deletenode);
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
    printf("Forword ptinting: ");
    printing_forword(head);
    printf("Backword ptinting: ");
    printing_backword(tail);

    insert_at_head(&head, 100);
    printf("Insert at head: ");
    printing_forword(head);

    insert_at_tail(&tail, 600);
    printf("Insert at tail: ");
    printing_forword(head);

    insert_at_any(head, 555, 3);
    printf("Insert at any pos: ");
    printing_forword(head);

    delete_at_head(&head);
    printf("Delete head: ");
    printing_forword(head);

    delete_at_tail(&tail);
    printf("Delete Tail: ");
    printing_forword(head);

    delete_at_any(head, 2);
    printf("Delete any: ");
    printing_forword(head);

    return 0;
}