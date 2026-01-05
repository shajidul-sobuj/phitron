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
int count(Node* &head)
{
    Node* temp = head;
    int cnt=0;
    while(temp!=NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
void printing_odd(Node* &head, int x)
{
    Node* temp = head;
    int idx = x/2;
    for (int i=0;i<idx;i++) {
        temp = temp->next;
    }
    cout << temp->val << endl;
}
void printing_even(Node* &head, int x)
{
    Node* temp = head;
    int idx = x/2;
    for (int i=0;i<idx-1;i++) {
        temp = temp->next;
    }
    cout << temp->val << " ";
    temp = temp->next;
    cout << temp->val << endl;
}
int main() {
    Node* head =  NULL;
    Node* tail = NULL;
    
    int x;
    while(cin >> x) {
        insert(head,tail,x);
    }
    int cnt = count(head);
    if (cnt%2==0) {
        printing_even(head,cnt);
    }else if (cnt%2!=0) {
        printing_odd(head,cnt);
    }

    return 0;
}