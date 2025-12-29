#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        long long n,k;
        cin >> n >> k;
        long long a[n];
        for (long long i=0;i<n;i++) {
            cin >> a[i];
        }
        long long mn = INT_MAX;
        for (long long i=0;i<n;i++) {
            if (a[i]>=k)
                mn = min(mn,(a[i]%k));
        }
        (mn == INT_MAX) ? cout << "-1\n" : cout << mn << endl;
    }
    return 0;
}