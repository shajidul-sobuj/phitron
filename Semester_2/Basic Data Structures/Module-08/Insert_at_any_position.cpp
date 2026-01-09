#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* next;
        Node* pre;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->pre = NULL;
    }
};

void insert_at_any(Node* &head, Node* &tail,int idx, int val)
{
    Node* newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    Node* temp = head;
    for (int i=0;i<idx-1;i++){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->pre = temp->next->pre;
    temp->next->pre = newnode;
    return; 
}

void printing_forword(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->pre = head;
    a->next = tail;
    tail->pre = a;

    insert_at_any(head,tail,2,100);
    insert_at_any(head,tail,1,200);
    printing_forword(head);

    return 0;
}