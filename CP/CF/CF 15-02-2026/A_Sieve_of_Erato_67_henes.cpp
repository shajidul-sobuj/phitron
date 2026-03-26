#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    bool yes = false;

    for (int i=0;i<n;i++)
    {
         if(a[i]==67)
        { 
            yes = true;
            break;
        }
    }
    if (yes)
        cout << "YES\n";
    else
        cout << "NO\n";
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