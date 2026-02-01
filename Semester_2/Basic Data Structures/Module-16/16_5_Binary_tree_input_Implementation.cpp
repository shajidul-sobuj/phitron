#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* left;
        Node* right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input()
{
    int val;
    cin >> val;
    Node* root;
    if (val==-1) 
    {
        root = NULL;
        return root;
    }
    root = new Node(val);
    queue <Node*> q;
    q.push(root);

    while(!q.empty())
    {
        // 1. Node ber kore ana
        Node* p = q.front();
        q.pop();

        // 2. oi node niye kaj
        int x,y;
        cin >> x >> y;
        Node *l, *r;
        if (x==-1)
        {
            l = NULL;
        }else{
            l = new Node(x);
        }

        if (y==-1)
        {
            r = NULL;
        }else{
            r = new Node(y);
        }

        // 3. children node push
        p->left = l;
        if (l)
        {
            q.push(l);
        }
        p->right = r;
        if (r)
        {
            q.push(r);
        }
    }
    return root;
}

void level_order(Node* root)
{
    if (root==NULL)
    {
        cout << "No tree\n";
        return;
    }
    queue <Node*> q;
    q.push(root);

    while(!q.empty())
    {
        // 1. node ber kore ana
        Node* f = q.front();
        q.pop();

        // 2. oi node niye kaj(print)
        cout << f->val << " ";

        // 3. children node push
        if(f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

void preorder(Node* temp)
{
    // if (temp==NULL)
    // {
    //     cout << "No tree\n";
    //     return;
    // }
    if (temp==NULL)
        return;
    cout << temp->val << " ";
    preorder(temp->left);
    preorder(temp->right);
}

int main() {
    Node* root = input();
    level_order(root);
    cout << endl;
    preorder(root);
    cout << endl;

    return 0;
}