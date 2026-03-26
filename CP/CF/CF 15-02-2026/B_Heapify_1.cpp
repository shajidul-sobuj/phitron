#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    long long n;
    cin >> n;
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    vector<long long> target(n + 1, 0), vis(n + 1, 0);
    iota(target.begin(), target.end(), 0ll);
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        vector<long long> kiKiNewaDrkr, targetki;
        for (int j = i; j <= n; j *= 2)
            kiKiNewaDrkr.push_back(arr[j]), targetki.push_back(target[j]), vis[j] = true;
        sort(kiKiNewaDrkr.begin(), kiKiNewaDrkr.end());
        if (kiKiNewaDrkr != targetki) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        Solve();
    }
    return 0;
}
