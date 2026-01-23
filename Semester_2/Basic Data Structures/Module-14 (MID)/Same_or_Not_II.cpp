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

class myStack
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
        return;
    }

    void pop()
    {
        sz--;
        Node* deletenode = tail;
        tail = tail->pre;
        delete deletenode;
        if (tail == NULL)
        {
            head = NULL;
            return;
        }
        tail->next = NULL;
        return;
    }

    int top()
    {
        return tail->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        if (sz==0)
        {
            return true;
        }else
        {
            return false;
        }
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
        return;
    }

    void pop()
    {
        sz--;
        Node* deletenode = head;
        head = head->next;
        delete deletenode;
        if (head == NULL)
        {
            tail = NULL;
            return;
        }
        head->pre = NULL;
        return;
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
        if (sz==0)
        {
            return true;
        }else
        {
            return false;
        }
    }
};

int main() {
    
    int n,m;
    cin >> n >> m;
    if (n!=m)
    {
        cout << "NO\n";
        return 0;
    }
    myStack st;
    myQueue q;
    while(n--)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    while(m--)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    while(!st.empty())
    {
        if (st.top()!=q.front())
        {
            cout << "NO\n";
            return 0;
        }
        st.pop();
        q.pop();
    }
    cout << "YES\n";
    return 0;
}