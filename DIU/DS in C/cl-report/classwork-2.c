#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

void traverse(struct node *head){
struct node *temp = head;
printf("\n\nList elements are - \n");
while(temp != NULL){
printf("%d --->",temp->data);
temp = temp->next;
}
}

struct node* insertAtBeginning(struct node *head,int data){
struct node *newNode = malloc(sizeof(struct node));
newNode->data = data;
newNode->next = head;
head = newNode;
return head;
}

struct node* insertAtEnd(struct node *head,int data){
struct node *newNode = malloc(sizeof(struct node));
newNode->data = data;
newNode->next = NULL;
if(head==NULL) return newNode;
struct node *temp = head;
while(temp->next != NULL){
temp = temp->next;
}
temp->next = newNode;
return head;
}

struct node* insertAtPosition(struct node *head,int data,int pos){
struct node *newNode = malloc(sizeof(struct node));
newNode->data = data;
if(pos==1){
newNode->next = head;
head = newNode;
return head;
}
struct node *temp = head;
for(int i=1;i<pos-1 && temp->next!=NULL;i++){
temp = temp->next;
}
newNode->next = temp->next;
temp->next = newNode;
return head;
}

struct node* deleteAtBeginning(struct node *head){
if(head==NULL) return head;
head = head->next;
return head;
}

struct node* deleteAtEnd(struct node *head){
if(head==NULL || head->next==NULL) return NULL;
struct node *temp = head;
while(temp->next->next!=NULL){
temp = temp->next;
}
temp->next = NULL;
return head;
}

struct node* deleteAtPosition(struct node *head,int pos){
if(pos==1){
head = head->next;
return head;
}
struct node *temp = head;
for(int i=1;i<pos-1 && temp->next!=NULL;i++){
temp = temp->next;
}
if(temp->next!=NULL)
temp->next = temp->next->next;
return head;
}

void search(struct node *head,int key){
int found = 0;
struct node *temp = head;
while(temp!=NULL){
if(temp->data==key){
found = 1;
break;
}
temp = temp->next;
}
if(found) printf("True\n");
else printf("False\n");
}

void update(struct node *head,int oldValue,int newValue){
int updated = 0;
struct node *temp = head;
while(temp!=NULL){
if(temp->data==oldValue){
temp->data = newValue;
updated = 1;
printf("Updated %d to %d\n",oldValue,newValue);
break;
}
temp = temp->next;
}
if(!updated){
printf("Value %d not found in the list.\n",oldValue);
}
}

struct node* reversal(struct node *head){
struct node *prev = NULL;
struct node *curr = head;
struct node *next1 = NULL;
while(curr!=NULL){
next1 = curr->next;
curr->next = prev;
prev = curr;
curr = next1;
}
head = prev;
return head;
}

int main()
{

struct node *head = NULL;

head = insertAtBeginning(head,20);
head = insertAtBeginning(head,10);
head = insertAtEnd(head,30);
head = insertAtEnd(head,40);
head = insertAtPosition(head,25,3);

head = deleteAtBeginning(head);
head = deleteAtEnd(head);
head = deleteAtPosition(head,2);

search(head,25);
update(head,25,35);

head = reversal(head);

traverse(head);

}
