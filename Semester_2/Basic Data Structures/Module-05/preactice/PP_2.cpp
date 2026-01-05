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
bool isfind(Node* temp) 
{
    Node* ck = temp->next;
    while(ck!=NULL) {
        if (ck->val == temp->val) {
            return true;
        }
        ck = ck->next;
    }
    return false;
}
void find(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL) {
        if (isfind(temp)) {
            cout << "YES\n";
            return;
        }
        temp = temp->next;
    }
    cout << "NO\n";
}
int main() {
    Node* head =  NULL;
    Node* tail = NULL;
    
    int x;
    while(cin >> x) {
        insert(head,tail,x);
    }
    find(head);

    return 0;
}