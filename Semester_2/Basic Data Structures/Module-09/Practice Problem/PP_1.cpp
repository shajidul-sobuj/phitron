#include <bits/stdc++.h>
using namespace std;

int main() {
    list <int> l1;
    list <int> l2;
    int x;
    while(cin >> x)
    {
        if (x==-1) break;
        l1.push_back(x);
    }
    while(cin >> x)
    {
        if (x==-1) break;
        l2.push_back(x);
    }
    bool isSame = true;
    if (l1.size()!=l2.size()) {
        cout << "NO\n";
        return 0;
    }
    while(!l1.empty())
    {
        if (l1.front()!=l2.front()) {
            isSame = false;
            break;
        }
        l1.pop_front();
        l2.pop_front();
    }
    if (isSame) 
        cout << "YES\n";
    else 
        cout << "NO\n";
    return 0;
}