#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin >> n >> k;
    int a[n];
    for (int i=0;i<n;i++) cin >> a[i];
    string s;
    cin >> s;
    int count_zero = 0;
    for (int i=0;i<n;i++)
    {
        if (s[i] == '0') count_zero++;
    }
    if (count_zero<k)
    {
        cout << -1 << "\n";
        return;
    }
    pair <int, char> p[n];
    for (int i=0;i<n;i++)
    {
        p[i].first = a[i];
        p[i].second = s[i];
    }
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (p[i].first > p[j].first) swap(p[i],p[j]);
        }
    }
    int cost = 0;
    for (int i=0;i<n;i++)
    {
        
        if (p[i].second == '0') 
        {
            cost += p[i].first;
            k--;
        }
        if (k == 0)
            break;
        // cout << p[i].first << " " << p[i].second << "\n";
    }
    cout << cost << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}