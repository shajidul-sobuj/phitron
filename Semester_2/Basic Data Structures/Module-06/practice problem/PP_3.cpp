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
    if (head==NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
    return;
}
void maximum_val(Node* head)
{
    int mx = INT_MIN;
    Node* temp = head;
    while (temp!=NULL)
    {
        mx = max(mx,temp->val);
        temp = temp->next;
    }
    cout << mx << endl;
    
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int x;
    while(cin >> x){
        if (x==-1) break;
        insert(head,tail,x);
    }
    maximum_val(head);
    return 0;
}