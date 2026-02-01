/*

        10
       /  \
     20    30
    /     /  \
  40     50   60
  
*/
/*------------------------*/
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

void in_tra(Node* temp)
{
    if(temp==NULL)
        return;
    in_tra(temp->left);
    cout << temp->val << " ";
    in_tra(temp->right);
}

int main() {

    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e; 
    
    // Node* root = new Node(1);
    // Node* b = new Node(2);
    // Node* c = new Node(3);
    // Node* d = new Node(4);
    // Node* e = new Node(5);
    // Node* f = new Node(6);
    // Node* g = new Node(7);
    // Node* h = new Node(8);
    // Node* i = new Node(9);
    // Node* j = new Node(10);

    // root->left = b;
    // root->right = c;
    // b->left = d;
    // b->right = e;
    // e->left = h;
    // c->left = f;
    // c->right = g;
    // g->left = i;
    // g->right = j;

    in_tra(root);

    return 0;
}














