#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long S = 0;
        for (int i = 0; i + 1 < n; i++) {
            S += abs(a[i] - a[i + 1]);
        }
        long long ans = S;
        for (int k = 0; k < n; k++) {
            long long cur = S;
            if (k > 0)
                cur -= abs(a[k] - a[k - 1]);
            if (k + 1 < n)
                cur -= abs(a[k] - a[k + 1]);
            if (k > 0 && k + 1 < n)
                cur += abs(a[k - 1] - a[k + 1]);
            ans = min(ans, cur);
        }
        cout << ans << "\n";
    }
    return 0;
}
