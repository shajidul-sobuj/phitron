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

void insert_at_head(Node **head,Node **tail, int val)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->next= NULL;
    newnode->val = val;

    if (*head == NULL)
        {
            *head = newnode;
            return;
        }
    newnode->next = *head;
    *head = newnode;
    return;
}

void insert_at_tail(Node **tail, int val)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->next= NULL;
    newnode->val = val;

    (*tail)->next = newnode;
    *tail = newnode;
    return;
}

void insert_at_any(Node *head, int val, int idx)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->next= NULL;
    newnode->val = val;
    Node *temp = head;
    for (int i=0;i<idx-1;i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return;
}

void delete_head(Node **head)
{
    Node* deletenode = *head;
    *head = (*head)->next;
    free(deletenode);
}

void delete_tail(Node *head, Node **tail)
{
    Node* deletenode = *tail;
    Node* temp = head;
    while(temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    *tail = temp;
    free(deletenode);
}

void delete_any(Node *head, int idx)
{
    Node* temp = head;
    for (int i=0;i<idx-1;i++)
    {
        temp = temp->next;
    }
    Node *deletenode = temp->next;
    temp->next = temp->next->next;
    free(deletenode);
}

void reverse_list(Node **head, Node *temp, Node **tail)
{
    if (temp->next == NULL)
    {
        *head = temp;
        return;
    }
    reverse_list(&head,temp->next,&tail);
    temp->next->next = temp;
    temp->next = NULL;
    *tail = temp;
}

void printing(Node *head)
{
    Node *temp = head;
    while(temp->next!=NULL)
    {
        printf("%d ->",temp->val);
        temp = temp->next;
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
        insert_val(&head,&tail,x);
    }
    printf("Created linkedlist: ");
    printing(head);

    printf("Insert value at head: ");
    insert_at_head(&head,&tail,100);
    printing(head);

    printf("Insert value at tail: ");
    insert_at_tail(&tail,500);
    printing(head);

    printf("Insert value at any: ");
    insert_at_any(head, 555, 3);
    printing(head);

    printf("Delete Head: ");
    delete_head(&head);
    printing(head);

    printf("Delete tail: ");
    delete_tail(head, &tail);
    printing(head);

    printf("Delete any pos: ");
    delete_any(head, 2);
    printing(head); 
 
    printf("Reverse list: ");
    reverse_list(&head, head, &tail);
    printing(head);
    return 0;
}