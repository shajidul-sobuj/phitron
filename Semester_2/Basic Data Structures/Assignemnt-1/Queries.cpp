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
    head = newnode;
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
    tail = newnode;
}
void delete_at_idx(Node* &head, Node* &tail, int idx) 
{
    if (head == NULL) 
        return;

    if (idx == 0) 
    {
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;

        if (head == NULL)  
            tail = NULL;
        return;
    }
    Node* tmp = head;
    for (int i=0;i<idx-1;i++) 
    {
        if (tmp->next == NULL) 
            return;
        tmp = tmp->next;
    }
    if (tmp->next == NULL) 
        return; 

    Node* deleteNode = tmp->next;
    tmp->next = deleteNode->next;
    if (deleteNode == tail)
        tail = tmp;
    delete deleteNode;
}
void print_list(Node* head) 
{
    Node* tmp = head;
    while (tmp != NULL) 
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int main() {
    int q;
    cin >> q;
    Node* head = NULL;
    Node* tail = NULL;
    while (q--) 
    {
        int x, val;
        cin >> x >> val;
        if (x == 0) 
        {
            insert_at_head(head, tail, val);
        }
        else if (x == 1) 
        {
            insert_at_tail(head, tail, val);
        }
        else if (x == 2) 
        {
            delete_at_idx(head, tail, val);
        }

        print_list(head);
    }


    return 0;
}