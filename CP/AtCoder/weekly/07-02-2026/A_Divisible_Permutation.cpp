#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i=n-2,val=n; i>=0; i=i-2,val--)
    {
        a[i] = val;
    }
    for (int i=n-1,val=1; i>=0; i=i-2,val++)
    {
        a[i] = val;
    }
    for (int x : a)
    {
        cout << x << " ";
    }
    cout << endl;
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