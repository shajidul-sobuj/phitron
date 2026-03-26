#include <bits/stdc++.h>
using namespace std;

class myQueue
{
    public: 
        list <int> l;

    void push(int val)
    {
        l.push_back(val);
    }
    void pop()
    {
        l.pop_front();
    }
    int front()
    {
        return l.front();
    }
    int back()
    {
        return l.back();
    }
    int size()
    {
        return l.size();
    }
    bool empty()
    {
        return l.empty();
    }

};

int main() {
    myQueue q;

    int x;
    while(cin >> x)
    {
        q.push(x);
    }

    cout << q.front() << " " << q.back() << " " << q.size() << endl;
    

    
    return 0;
}