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

class myQueue
{
    public: 
        Node* head = NULL;
        Node* tail = NULL;
        int sz = 0;

    void push(int val)
    {
        sz++;
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
    }
    void pop()
    {
        sz--;
        Node* deletenode = head;
        head = head->next;
        delete deletenode;
        if(head == NULL)
        {
            tail = NULL;
            return;
        }
        head->pre = NULL;
    }
    int front()
    {
        return head->val;
    }
    int back()
    {
        return tail->val;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        if (sz == 0)
            return true;
        else   
            return false;
    }

};

int main() {
    myQueue q;

    int x;
    while(cin >> x)
    {
        q.push(x);
    }

    cout << q.front() << " " << q.back() << " " << q.size() << endl;
    
    return 0;
}