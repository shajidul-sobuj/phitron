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
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
    return;
}
void reverse_print(Node* temp)
{
    if (temp==NULL) return;
    reverse_print(temp->next);
    cout << temp->val << " ";
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int x;
    while(cin >> x){
        if (x==-1) break;
        insert(head,tail,x);
    }
    reverse_print(head);
    return 0;
}