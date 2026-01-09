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

int n=-1;

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

void insert_at_head(Node* &head,int val)
{
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
    return;
}

void insert_at_tail(Node* &tail,int val)
{
    Node* newnode = new Node(val);
    tail->next = newnode;
    tail = newnode;
}

void insert_at_any(Node* &head,int idx,int val)
{
    Node* temp = head;
    Node* newnode = new Node(val);
    for (int i=0;i<idx-1;i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void printing(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int x;
    while(cin >> x){
        if (x==-1) break;
        insert(head,tail,x);
        n++;
    }
    // cout << n << endl;
    int q;
    cin >> q;
    while(q--)
    {
        int idx,val;
        cin >> idx >> val;
        if(idx>n+1) {
            cout << "Invalid\n";
            continue;
        }
        if(idx==0) {
            insert_at_head(head,val);
            n++;
        }else if(idx==n+1) {
            insert_at_tail(tail,val);
            n++;
        }else {
            insert_at_any(head,idx,val);
            n++;
        }
        printing(head);
        cout << endl;
    }
    return 0;
}