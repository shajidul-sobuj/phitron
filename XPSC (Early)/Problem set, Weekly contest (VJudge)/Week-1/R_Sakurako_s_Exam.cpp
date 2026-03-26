#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b;
    cin >> a >> b;

    if ((a == 0 && b%2 != 0) || (b == 0 && a%2 != 0)) {
        cout << "NO\n";
        return;
    }

    if (a == 0 && b%2 == 0)
    {
        cout << "YES\n";
        return;
    }
    if (b == 0 && a%2 == 0)
    {
        cout << "YES\n";
        return;
    }

    long long int x = a-((b%2)*2);
    if ( x%2 == 0)
    {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
    
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}