#include <bits/stdc++.h>
using namespace std;

void pookie()
{
    int n;
    cin >> n;
    pair<int, int> p[n];
    for (int i=0;i<n;i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    int mn = INT_MAX;
    bool no7 = true;
    for (int i=0;i<n;i++)
    {
        if (p[i].first >= 7)
        {
            no7 = false;
            break;
        }
    }
    for (int i=0;i<n;i++)
    {
        if (p[i].first >= 7)
        {
            mn = min(mn,p[i].second);
        }
    }
    if (no7)
        cout << -1 << endl;
    else
        cout << mn << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        pookie();
    }
    return 0;
}