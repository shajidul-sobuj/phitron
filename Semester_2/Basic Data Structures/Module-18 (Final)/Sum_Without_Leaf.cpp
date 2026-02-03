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

Node* input_tree()
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
        Node* p = q.front();
        q.pop();

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

int suum_without_leaf(Node* root )
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;
    int l=suum_without_leaf(root->left);
    int r=suum_without_leaf(root->right);
    return l+r+root->val;
}

int main() {
    Node* root = input_tree();
    int ans = suum_without_leaf(root);
    cout << ans << endl;

    return 0;
}