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

void insert(Node* &head, Node* &tail, int val)
{
    Node* newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->pre = tail;
    tail = newnode;
    return;
}

void check(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
    while (temp1!=NULL)
    {
        if (temp1->val != temp2->val) {
            cout << "NO\n";
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    cout << "YES\n";
    return;
}

int siz(Node* head)
{
    int c = 0;
    Node* temp = head;
    while (temp!=NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;

    int x;
    while(cin >> x) {
        if (x == -1) break;
        insert(head1,tail1,x);
    }
    while(cin >> x) {
        if (x == -1) break;
        insert(head2,tail2,x);
    }
    int sz1 = siz(head1);
    int sz2 = siz(head2);

    if (sz1!=sz2) { 
        cout << "NO\n";
    } 
    else {
        check(head1,head2);
    }
    return 0;
}