/*
            1
          /   \
         7     9
        / \     \
       2   6     9
          / \   /
         5  11 5
*/

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

void preorder(Node* temp)
{
    if(temp==NULL)
        return;
    
    cout << temp->val << " ";
    preorder(temp->left);
    preorder(temp->right);
    
}
void inorder(Node* temp)
{
    if(temp==NULL)
        return;
    
    
    inorder(temp->left);
    cout << temp->val << " ";
    inorder(temp->right);
    
}
void postorder(Node* temp)
{
    if(temp==NULL)
        return;
    
    
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->val << " ";
}

int main() {
    Node* root = new Node(1);
    Node* a = new Node(7);
    Node* b = new Node(9);
    Node* c = new Node(2);
    Node* d = new Node(6);
    Node* e = new Node(5);
    Node* f = new Node(11);
    Node* g = new Node(9);
    Node* h = new Node(5);

    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    d->left = e;
    d->right = f;
    b->right = g;
    g->left = h;


    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;
}