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
    newnode->pre = tail;
    tail = newnode;
    return;
}

void printing(Node* head)
{
    Node* temp = head;
    while (temp!=NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
    return;
}

void reverse_linked_list(Node* head, Node* tail)
{
    for (Node *i=head, *j=tail; i!=j && i->pre!=j; i=i->next, j=j->pre)
    {
        swap(i->val,j->val);
    }
}   

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insert(head, tail, 10);
    insert(head, tail, 20);
    insert(head, tail, 30);
    insert(head, tail, 40);


    reverse_linked_list(head, tail);
    printing(head);
    
    return 0;
}