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
void count(Node* &head)
{
    Node* temp = head;
    int cnt=0;
    while(temp!=NULL) {
        cnt++;
        temp = temp->next;
    }
    cout << cnt << endl;
}
int main() {
    Node* head =  NULL;
    Node* tail = NULL;
    
    int x;
    while(cin >> x) {
        insert(head,tail,x);
    }
    count(head);

    return 0;
}