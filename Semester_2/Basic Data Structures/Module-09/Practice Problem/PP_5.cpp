#include <bits/stdc++.h>
using namespace std;

int main() {
    list <int> l;
    
    int x;
    while(cin >> x)
    {
        if (x==-1) break;
        l.push_back(x);
    }
    l.sort();

    for (int t : l)
    {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}