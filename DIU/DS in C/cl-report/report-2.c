#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

void traverse(struct node *head){
if(head==NULL) return;
struct node *temp = head;
printf("\n\nList elements are - \n");
do{
printf("%d --->",temp->data);
temp = temp->next;
}while(temp!=head);
}

struct node* insertAtBeginning(struct node *head,int data){
struct node *newNode = malloc(sizeof(struct node));
newNode->data = data;
if(head==NULL){
newNode->next = newNode;
return newNode;
}
struct node *temp = head;
while(temp->next!=head){
temp = temp->next;
}
newNode->next = head;
temp->next = newNode;
head = newNode;
return head;
}

struct node* insertAtEnd(struct node *head,int data){
struct node *newNode = malloc(sizeof(struct node));
newNode->data = data;
if(head==NULL){
newNode->next = newNode;
return newNode;
}
struct node *temp = head;
while(temp->next!=head){
temp = temp->next;
}
temp->next = newNode;
newNode->next = head;
return head;
}

struct node* insertAtPosition(struct node *head,int data,int pos){
if(pos==1) return insertAtBeginning(head,data);
struct node *newNode = malloc(sizeof(struct node));
newNode->data = data;
struct node *temp = head;
for(int i=1;i<pos-1 && temp->next!=head;i++){
temp = temp->next;
}
newNode->next = temp->next;
temp->next = newNode;
return head;
}

struct node* deleteAtBeginning(struct node *head){
if(head==NULL) return head;
if(head->next==head) return NULL;
struct node *temp = head;
while(temp->next!=head){
temp = temp->next;
}
temp->next = head->next;
head = head->next;
return head;
}

struct node* deleteAtEnd(struct node *head){
if(head==NULL) return head;
if(head->next==head) return NULL;
struct node *temp = head;
while(temp->next->next!=head){
temp = temp->next;
}
temp->next = head;
return head;
}

struct node* deleteAtPosition(struct node *head,int pos){
if(pos==1) return deleteAtBeginning(head);
struct node *temp = head;
for(int i=1;i<pos-1 && temp->next!=head;i++){
temp = temp->next;
}
if(temp->next!=head)
temp->next = temp->next->next;
return head;
}

void search(struct node *head,int key){
if(head==NULL){
printf("False\n");
return;
}
int found = 0;
struct node *temp = head;
do{
if(temp->data==key){
found = 1;
break;
}
temp = temp->next;
}while(temp!=head);
if(found) printf("True\n");
else printf("False\n");
}

void update(struct node *head,int oldValue,int newValue){
if(head==NULL){
printf("Value %d not found in the list.\n",oldValue);
return;
}
int updated = 0;
struct node *temp = head;
do{
if(temp->data==oldValue){
temp->data = newValue;
updated = 1;
printf("Updated %d to %d\n",oldValue,newValue);
break;
}
temp = temp->next;
}while(temp!=head);
if(!updated){
printf("Value %d not found in the list.\n",oldValue);
}
}

struct node* reversal(struct node *head){
if(head==NULL || head->next==head) return head;
struct node *prev = NULL;
struct node *curr = head;
struct node *next1 = NULL;
struct node *tail = head;
while(tail->next!=head){
tail = tail->next;
}
do{
next1 = curr->next;
curr->next = prev;
prev = curr;
curr = next1;
}while(curr!=head);
head->next = prev;
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
