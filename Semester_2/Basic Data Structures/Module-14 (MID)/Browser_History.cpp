#include <bits/stdc++.h>
using namespace std;

class Node
{
    public: 
        string site;
        Node* next;
        Node* pre;

        Node(string site)
        {
            this->site = site;
            this->next = NULL;
            this->pre = NULL;
        }
};

void insert(Node* &head, Node* &tail, string site)
{
    Node* newnode = new Node(site);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->pre = tail;
    tail = newnode;
    return;
}

void position(Node* &head, Node* &track, string pos)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if (temp->site==pos)
        {
            track = temp;
            return;
        }
        temp = temp->next;
    }

}

void print1(Node* &track, string pos)
{
    if (track->site == pos)
    {
        cout << track->site << endl;
    }
    else
    {
        cout << "Not Available\n";
    }
}

void print_next(Node* &track)
{
    if(track->next!=NULL)
    {
        track = track->next;
        cout << track->site << endl;
    }else{
        cout << "Not Available\n";
    }
}

void print_pre(Node* &track)
{
    if(track->pre!=NULL)
    {
        track = track->pre;
        cout << track->site << endl;
    }else{
        cout << "Not Available\n";
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    string s;
    while(cin >> s)
    {
        if (s == "end") break;
        insert(head, tail, s);
    }
    Node* track = NULL;
    int t;
    cin >> t;
    while(t--)
    {
        string command;
        cin >> command;
        if (command == "visit")
        {
            string pos;
            cin >> pos;
            position(head, track, pos);
            print1(track, pos);
        }
        else if (command == "next") 
        {
            print_next(track);
        }
        else if (command == "prev")
        {
            print_pre(track);
        }
    }
    return 0;
}