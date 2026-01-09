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

void delete_at_any(Node* &head, Node* &tail, int idx)
{
    Node* temp = head;
    for (int i=0;i<idx-1;i++) {
        temp = temp->next;
    }
    Node* deletenode = temp->next;
    temp->next = deletenode->next;
    deletenode->next->pre = deletenode->pre;
    delete deletenode;
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

    delete_at_any(head,tail,1);
    print_forword(head,tail);


    return 0;
}