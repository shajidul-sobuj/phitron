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

void insert_at_head(Node* &head, Node* &tail, int val)
{
    Node* newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->pre = newnode;
    head = newnode;
    return;
}

void inserty_at_any(Node* &head, Node* &tail, int val, int idx)
{
    Node* newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    Node* temp = head;
    for (int i=0;i<idx-1;i++)
    {
        temp = temp->next;
    }
    newnode->pre = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->pre = newnode;
    return;
}

void insert_at_tail(Node* &head, Node* &tail, int val)
{
    Node* newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->pre = tail;
    tail = newnode;
    return;
}

void fprint(Node* head)
{
    Node* temp = head;
    cout << "L -> ";
    while(temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void bprint(Node* tail)
{
    Node* temp = tail;
    cout << "R -> ";
    while(temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->pre;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int t;
    cin >> t;
    int n=0;
    while(t--)
    {
        int x,v;
        cin >> x >> v;
        if (x==0)
        {
            n++;
            insert_at_head(head,tail,v);
        }
        else if (x>n)
        {
            cout << "Invalid\n";
            continue;
        }
        else if(x>0 && x<n) {
            n++;
            inserty_at_any(head,tail,v,x);
        }
        else if (x==n)
        {
            n++;
            insert_at_tail(head,tail,v);
        }

        fprint(head);
        bprint(tail);
    }
    return 0;
}