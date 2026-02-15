#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    // 1->2->3

    // pointer initialization

    struct node *head;
    struct node *one;
    struct node *two;
    struct node *three;

    // node memory allocation
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    // data initialize

    one->data = 1;
    two->data = 2;
    three->data = 3;

    // link creation
    one->next = two;
    two->next = three;
    three->next = NULL;

    // head should be my first pointer
    head = one;

    // 4->1->2->3(insert at beginning)
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = 4;
    newNode->next = head;
    head = newNode;

    // 4->1->2->3->5(insert at end)
    struct node *newNode1;
    newNode1 = malloc(sizeof(struct node));
    newNode1->data = 5;
    newNode1->next = NULL;

    struct node *temp1 = head;

    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = newNode1;

    // 4->1->2->6->3->5(insert at middle)

    struct node *newNode2;
    newNode2 = malloc(sizeof(struct node));
    newNode2->data = 6;

    struct node *temp2 = head;

    for (int i = 2; i < 4; i++)
    {
        if (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
    }
    newNode2->next = temp2->next;
    temp2->next = newNode2;

    // 1->2->6->3->5(delete at beginning)
    head = head->next;

    // 1->2->6->3(delete at end)
    struct node *temp3 = head;
    while (temp3->next->next != NULL)
    {
        temp3 = temp3->next;
    }
    temp3->next = NULL;

    // 1->2->3
    struct node *temp4 = head;
    for (int i = 2; i < 3; i++)
    {
        if (temp4->next != NULL)
        {
            temp4 = temp4->next;
        }
    }

    temp4->next = temp4->next->next;

    // search (do with 3, and 4)
    int key = 4;
    int found = 0;
    struct node *current = head;

    while (current != NULL)
    {
        if (current->data == key)
        {
            found = 1;
            break;
        }
        current = current->next;
    }

    if (found)
        printf("True\n");
    else
        printf("False\n");

    // update 3 to 4

    int oldValue = 3, newValue = 4;
    int updated = 0;

    struct node *current1 = head;

    while (current1 != NULL)
    {
        if (current1->data == oldValue)
        {
            current1->data = newValue;
            updated = 1;
            printf("Updated %d to %d\n", oldValue, newValue);
            break; // remove this if you want to update all occurrences
        }
        current1 = current1->next;
    }

    if (!updated)
    {
        printf("Value %d not found in the list.\n", oldValue);
    }
    // reversal
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next1 = NULL;
    while (curr != NULL)
    {
        next1 = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next1;
    }
    head = prev;

    // traverse
    struct node *temp = head;
    printf("\n\nList elements are - \n");
    while (temp != NULL)
    {
        printf("%d --->", temp->data);
        temp = temp->next;
    }
}