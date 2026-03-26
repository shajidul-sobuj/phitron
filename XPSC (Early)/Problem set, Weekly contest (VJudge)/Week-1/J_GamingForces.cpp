#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    int ans = 0;
    int count_one = 0;
    for (int x : a)
    {
        if (x == 1) count_one++;
        else ans++;
    }
    if (count_one%2==0) ans+=(count_one/2);
    else ans+=(count_one/2)+1;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}