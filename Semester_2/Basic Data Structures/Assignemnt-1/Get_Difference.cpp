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

void insert(Node* &head, Node* &tail, int val) {
    
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}
int max_min(Node* head) {
    if (head == NULL){
        return 0;
    } 

    int max = head->val;
    int min = head->val;
    Node* tmp = head;
    while (tmp != NULL) {
        if (tmp->val > max){
            max = tmp->val;

        } 
        if (tmp->val < min){
            min = tmp->val;
        } 
        tmp = tmp->next;
    }
    return max - min;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    
    int n;
    while (1) {
        cin >> n;
        if (n!= -1) {
            insert(head,tail,n);
        } 
        else {
            break;
        }
    }
    
    cout << max_min(head) << endl;



    return 0;
}