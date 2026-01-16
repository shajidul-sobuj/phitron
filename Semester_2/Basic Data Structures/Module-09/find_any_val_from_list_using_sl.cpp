#include <bits/stdc++.h>
using namespace std;

int main() {
    list <int> l = {10,20,30,20,50,20};
    auto it = find(l.begin(),l.end(),200);
    if (it == l.end()) cout << "NO\n";
    else cout << "YES\n";
    for (int x : l)
    {
        cout << x << " ";
    }
    return 0;
}