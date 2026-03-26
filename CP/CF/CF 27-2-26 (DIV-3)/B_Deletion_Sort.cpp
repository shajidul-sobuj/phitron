#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i=0;i<n;i++)
        cin >> a[i];
    bool non = true;
    for (int i=1;i<n;i++)
    {
        if (a[i] < a[i-1]) 
        {
            non = false;
            break;
        }
    }
    if (non)
        cout << n << "\n";
    else
        cout << 1 << "\n";
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