#include <bits/stdc++.h>
using namespace std;

void solve()
{
        long long int n, m, k;
        cin >> n >> m >> k;
        long long int ans = min(n,k)*min(m,k);
        cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        solve();
    }

    return 0;
}
