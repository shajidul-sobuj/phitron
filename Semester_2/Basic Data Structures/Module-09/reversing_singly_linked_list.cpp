#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert(Node* &head, Node* &tail, int val)
{
    Node* newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
    return;
}

void printing(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

void reverse(Node* temp, Node* &head, Node* &tail)
{
    if(temp->next==NULL)
    {
        head = temp;
        return;
    }
    reverse(temp->next, head, tail);
    temp->next->next = temp;
    temp->next = NULL;
    tail = temp; 
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insert(head,tail,10);
    insert(head,tail,20);
    insert(head,tail,30);

    reverse(head,head,tail);

    printing(head);
    cout << endl << tail->val << endl << head->val << endl;

    return 0;
}