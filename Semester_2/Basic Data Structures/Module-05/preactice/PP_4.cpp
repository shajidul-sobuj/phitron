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
void insert(Node* &head, Node* &tail,int val)
{
    Node* newnode = new Node(val);
    if (head==NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
    return;
}
bool is_no(Node* temp) 
{
    Node* ck = temp->next;
        if (ck->val < temp->val) {
            return true;
        }
    return false;
}
void is(Node* &head)
{
    Node* temp = head;
    while(temp->next!=NULL) {
        if (is_no(temp)) {
            cout << "NO\n";
            return;
        }
        temp = temp->next;
    }
    cout << "YES\n";
}
int main() {
    Node* head =  NULL;
    Node* tail = NULL;
    
    int x;
    while(cin >> x) {
        insert(head,tail,x);
    }
    is(head);

    return 0;
}