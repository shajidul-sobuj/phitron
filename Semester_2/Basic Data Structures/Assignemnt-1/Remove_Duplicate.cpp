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

void insert_at_any_pos(Node* head, int idx, int val)
{
    Node* newnode = new Node(val);

    Node* tmp = head;
    for (int i=1;i<idx;i++)
    {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;       
}

int size_of_sll(Node* head)
{
    Node* temp = head;
    int sz = 0;
    while (temp != NULL)
    {
        sz++;
        temp = temp->next;
    }
    return sz;
}

void print_sll(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int fre[100005] = {0};
    int val;
    while (cin >> val)
    {
        if (val == -1)
            break;

        if (fre[val] == 0)
        {
            fre[val]++;
            insert_at_tail(head, tail, val);
        }
    }

    print_sll(head);

    return 0;
}