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

void printing_backword(Node* tail)
{
    Node* temp = tail;
    while(temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->pre;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->next = tail;
    a->pre = head;
    tail->pre = a;


    printing_forword(head);
    printing_backword(tail);
    return 0;
}