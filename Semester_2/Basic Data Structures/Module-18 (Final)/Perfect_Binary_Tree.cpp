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

int count_min_one = 0;

Node* input_tree()
{
    int val;
    cin >> val;
    Node* root;
    if (val==-1) 
    {
        count_min_one++;
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
            count_min_one++;
            l = NULL;
        }else{
            l = new Node(x);
        }

        if (y==-1)
        {
            count_min_one++;
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

int main() {
    Node* root = input_tree();
    int h = max_hight(root);
    // cout << h << endl;
    if (pow(2,h)*2==count_min_one)
        cout << "YES\n";
    else 
        cout << "NO\n";
    return 0;
}