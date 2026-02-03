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

int max_hight(Node* root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 0;
    
    int l = max_hight(root->left);
    int r = max_hight(root->right);
    return max(l,r)+1;
}

void print_k_nodes(Node* root, int k)
{
    if (root == NULL)
    {
        return;
    }
    queue <pair <Node*, int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        Node* p = q.front().first;
        int level = q.front().second;
        q.pop();

        if (level == k)
        {
            cout << p->val << " ";
        }

        if(p->left)
        {
            q.push({p->left,level+1});
        }
        if(p->right)
        {
            q.push({p->right,level+1});
        }

    }

}

int main() {
    Node* root = input_tree();
    int k;
    cin >> k;
    
    int h = max_hight(root);
    // cout << h << endl;
    if (k<0 || k>h)
    {
        cout << "Invalid\n";
        return 0;
    }
    print_k_nodes(root,k);

    return 0;
}