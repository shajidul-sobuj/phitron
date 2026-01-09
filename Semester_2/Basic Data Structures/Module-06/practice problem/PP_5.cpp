#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert(Node* &head, Node* &tail, int val)
{
    Node* newnode = new Node(val);
    if (head==NULL){
        head = newnode;;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
    return;
}

void sort_in_d(Node* &head)
{
    for (Node* i=head;i->next!=NULL;i=i->next){
        for (Node* j = i->next;j!=NULL;j=j->next) {
            if (i->val<j->val){
                swap(i->val,j->val);
            }
        }
    }
    return;
}

void printing(Node* head)
{
    Node* temp = head;
    while(temp!=NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int x;
    while(cin >> x){
        if (x==-1) break;
        insert(head,tail,x);
    }
    sort_in_d(head);
    printing(head);
    return 0;
}