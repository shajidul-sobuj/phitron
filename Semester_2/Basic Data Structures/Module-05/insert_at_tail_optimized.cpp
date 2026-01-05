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
void insert_at_tail(Node* &tail, int val)
{
    Node* newnode = new Node(val);
    tail->next = newnode;
    tail = newnode;
}
void printing(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL) {
        cout << temp->val << endl;
        temp = temp->next;
    }
}
int main() {
    
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->next = tail;

    insert_at_tail(tail,40);
    insert_at_tail(tail,50);
    printing(head);
    cout << "tail: " << tail->val << endl;


    return 0;
}