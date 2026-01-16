#include <bits/stdc++.h>
using namespace std;

int main() {
    list <int> l1;
    int x;
    while(cin >> x)
    {
        if (x==-1) break;
        l1.push_back(x);
    }
    list <int> l2(l1);
    l2.reverse();
    bool isSame = true;
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