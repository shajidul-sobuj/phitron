#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n,l,r;
    cin >> n >> l >> r;
    vector <long long int> v(n+1);
    for (int i=1;i<=n;i++) cin >> v[i];
    int pos = -1;
    long long int mx = LLONG_MIN;
    for (int i=1;i<=n;i++)
    {
        if (v[i]>=l && v[i]<=r && v[i]>mx)
        {
            mx = v[i];
            pos = i;
        }
    }
    cout << pos << endl;
    return 0;
}