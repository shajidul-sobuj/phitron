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
int count(Node* head)
{
    Node* temp = head;
    int coun = 0;
    while(temp!=NULL) {
        coun++;
        temp = temp->next;
    }
    return coun;
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int x;
    while(cin >> x){
        if (x==-1) break;
        insert(head,tail,x);
    }
    
    Node* head2 = NULL;
    Node* tail2 = NULL;
    while(cin >> x){
        if (x==-1) break;
        insert(head2,tail2,x);
    }
    int list1 = count(head);
    int list2 = count(head2);
    (list1==list2) ? cout << "YES\n" : cout << "NO\n";
    return 0;
}