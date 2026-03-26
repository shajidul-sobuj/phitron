#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n,x;
    cin >> n >> x;
    vector<long long int> a(n);
    for (long long int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    if (a[n-1]<x){
        cout << 0 << endl;
        return;
    }
    long long int extra = 0;
    long long int count = 0;
    for (long long int i=n-1;i>=0;i--)
    {
        long long int k = a[i]+extra;
        if (k>=x)
        {
            count++;
            extra = k-x;
        }
    }
    cout << count << endl;
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