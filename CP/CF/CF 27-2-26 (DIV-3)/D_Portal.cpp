#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x, y;
        cin >> n >> x >> y;

    vector<int> p(n);
    for (int i=0;i<n;i++)
        cin >> p[i];
    vector<int> B;
    for (int i=x;i<y;i++)
        B.push_back(p[i]);

    vector<int> out;
    for (int i=0;i<x;i++)
        out.push_back(p[i]);
    for (int i=y;i<n;i++)
        out.push_back(p[i]);

    sort(out.begin(), out.end());

    vector<int> ans;
    int optr = 0; 
    int bptr = 0; 

    for (int i=0;i<n;i++) 
    {
        if (i >= x && i < y) 
            ans.push_back(B[bptr++]);
        else 
            ans.push_back(out[optr++]);
    }

    for (int g : ans)
        cout << g << " ";
    cout << "\n";
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
}