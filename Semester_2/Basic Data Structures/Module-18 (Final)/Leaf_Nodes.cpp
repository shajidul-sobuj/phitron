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

vector<int> leaf_nodes(Node* root)
{
    vector<int> v;
    if (root == NULL)
        return v;

    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(root->val);
        return v;
    }

    vector<int> l = leaf_nodes(root->left);
    vector<int> r = leaf_nodes(root->right);

    v.insert(v.end(), l.begin(), l.end());
    v.insert(v.end(), r.begin(), r.end());
    return v;
}


int main() {
    
    Node* root = input_tree();
    vector <int> v = leaf_nodes(root);
    sort(v.begin(),v.end());
    for (int i=v.size()-1;i>=0;i--)
    {
        cout << v[i] << " ";
    }

    return 0;
}