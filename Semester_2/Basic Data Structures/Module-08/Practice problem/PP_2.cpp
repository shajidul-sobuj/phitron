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
    if (head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->pre = tail;
    tail = newnode;
    return;
}

void printing(Node* tail)
{
    Node* temp = tail;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->pre;
    }
    return;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int x;
    while(cin >> x){
        if (x==-1) break;
        insert(head,tail,x);
    }

    printing(tail);

    return 0;
}