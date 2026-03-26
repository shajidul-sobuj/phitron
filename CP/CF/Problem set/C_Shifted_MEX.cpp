#include <bits/stdc++.h>
using namespace std;

void pookie()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    int mx = INT_MIN;
    for (int i=0;i<n;i++)
    {
        mx = max(mx,v[i]);
    }
    // mx = -mx;
    for (int i=0;i<n;i++)
    {
        v[i] = v[i]-mx;
    }
    cout << 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        pookie();
    }
    return 0;
}