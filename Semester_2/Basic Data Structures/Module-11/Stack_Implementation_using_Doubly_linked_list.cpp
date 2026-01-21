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
            Node *newnode = new Node(val);
            if (head == NULL)
            {
                head = newnode;
                tail = newnode;
                return;
            }
            newnode->pre = tail;
            tail->next = newnode;
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
            if(head == NULL) 
                return true;
            else
                return false;
        }
};

int main() {
    myStack st;
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    cout << st.size() << endl;

    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}

