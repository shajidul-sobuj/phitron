#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n,k;
    cin >> n >> k;
    vector <long long int> t(n);
    for (long long int i=0;i<n;i++) cin >> t[i];
    long long int mx = INT_MIN;
    for (long long int i=0;i<n-(k-1);i++)
    {
        long long int mx1 = INT_MIN;
        long long int mn1 = INT_MAX;

        for (long long int j=i;j<=k;j++)
        {
            mx1 = max(mx1,t[j]);
            mn1 = min(mn1,t[i]);
        }
        mx = max(mx,mx1-mn1);
    }
    cout << mx << endl;
    return 0;
}

