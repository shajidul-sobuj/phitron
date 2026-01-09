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

void delete_at_head(Node* &head, Node* &tail)
{
    Node* deletenode = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
        return;
    }
    head->pre = NULL;
    return;
}

void print_forword(Node* head, Node* tail)
{
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->pre = head;
    a->next = tail;
    tail->pre = a;

    delete_at_head(head,tail);
    print_forword(head,tail);


    return 0;
}