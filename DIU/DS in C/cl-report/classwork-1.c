#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;

};

int main()
{

struct node *head;
struct node *one;
struct node *two;
struct node *three;

one= malloc(sizeof(struct node));
two=malloc(sizeof(struct node));
three=malloc(sizeof(struct node));

one->data=10;
two->data=20;
three->data=30;

one->next=two;
two->next=three;
three->next=NULL;

head=one;

struct node *newNode;
newNode = malloc(sizeof(struct node));
newNode->data = 5;
newNode->next = head;
head = newNode;

struct node *newNode1;
newNode1 = malloc(sizeof(struct node));
newNode1->data = 40;
newNode1->next = NULL;

struct node *temp1=head;

while(temp1->next != NULL) {
temp1 = temp1->next;
}
temp1->next=newNode1;

struct node *newNode2;
newNode2 = malloc(sizeof(struct node));
newNode2->data = 25;

struct node *temp2 = head;

for(int i=2; i < 3; i++) {
if(temp2->next != NULL) {
temp2 = temp2->next;
}
}
newNode2->next = temp2->next;
temp2->next = newNode2;

head=head->next;

struct node* temp3 = head;
while(temp3->next->next!=NULL){
temp3 = temp3->next;
}
temp3->next = NULL;

struct node *temp4=head;
for(int i=2; i< 3; i++) {
if(temp4->next!=NULL) {
temp4 = temp4->next;
}
}

temp4->next = temp4->next->next;

int key=25;
int found = 0;
struct node *current = head;

while (current != NULL) {
if (current->data == key) {
found = 1;
break;
 }
current = current->next;
}

if (found)
 printf("True\n");
else
printf("False\n");

int oldValue = 30, newValue = 35;
int updated = 0;

struct node* current1 = head;

while (current1 != NULL) {
if (current1->data == oldValue) {
current1->data = newValue;
updated = 1;
 printf("Updated %d to %d\n", oldValue, newValue);
 break;
}
current1 = current1->next;
}

if (!updated) {
printf("Value %d not found in the list.\n", oldValue);
}

struct node* prev = NULL;
struct node* curr = head;
struct node* next1 = NULL;
while (curr != NULL) {
next1 = curr->next;
curr->next = prev;
prev = curr;
curr = next1;
}
head = prev;

struct node *temp = head;
printf("\n\nList elements are - \n");
while(temp != NULL) {
printf("%d --->",temp->data);
temp = temp->next;
}

}
