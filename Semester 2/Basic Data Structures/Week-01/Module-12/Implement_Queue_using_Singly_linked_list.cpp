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

    cout << "size " << q.size() << endl;

    while(!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    

    
    return 0;
}