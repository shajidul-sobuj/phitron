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
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
    return;
}
void printing(Node* head)
{
    Node* temp = head;
    while(temp!=NULL) {
        cout << temp->val << endl;
        temp = temp->next;
    }
    return;
}
void deleteany(Node* &head,int idx)
{
    Node* temp = head;
    for (int i=0;i<idx-1;i++) {
        temp = temp->next;
    }
    Node* deletenode = temp->next;;
    temp->next = temp->next->next;
    delete deletenode;
    return;
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int x;
    while(cin >> x){
        if (x==-1) break;
        insert(head,tail,x);
    }
    deleteany(head,4);
    printing(head);

    return 0;
}