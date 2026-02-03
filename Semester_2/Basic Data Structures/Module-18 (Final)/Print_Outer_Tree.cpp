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

void print_left_outer(Node* temp)
{
    if (temp == NULL)
        return;
    
    if (temp->left == NULL && temp->right == NULL)
    {
        cout << temp->val << " ";
        return;
    }

    if (temp->left)
    {
        print_left_outer(temp->left);
        cout << temp->val << " ";
    }else if (temp->right)
    {
        print_left_outer(temp->right);
        cout << temp->val << " ";
    }
}

void print_right_outer(Node* temp)
{
    if (temp == NULL)
        return;
    if (temp->left == NULL && temp->right == NULL)
    {
        cout << temp->val << " ";
        return;
    }
    if (temp->right)
    {
        cout << temp->val << " ";
        print_right_outer(temp->right);
    }else if (temp->left)
    {
        cout << temp->val << " ";
        print_right_outer(temp->left);
    }
}

int main()
{
    Node* root = input_tree();
    if (root == NULL) return 0;
    if (root->left){
        print_left_outer(root->left);
    }
        
    cout << root->val << " ";

    if (root->right){
        print_right_outer(root->right);
    }
        
    

    return 0;
}
