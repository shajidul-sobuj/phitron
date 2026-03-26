#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (long long int i=0;i<n;i++) cin >> a[i];
    long long int mx = INT_MIN;
    for (long long int i=0;i<n-1;i++)
    {
        for (long long int j=i+1;j<n;j++)
        {
            if (a[i]==a[j])
                mx = max(mx,(j+1-i));
        }
    }
    cout << mx << endl;
    return 0;
}