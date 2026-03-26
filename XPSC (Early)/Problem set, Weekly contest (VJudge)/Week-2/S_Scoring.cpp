#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x,y;
    cin >> x >> y;
    int a,b;
    b = (y-x)/2;
    a = y-b;
    cout << a << " " << b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}