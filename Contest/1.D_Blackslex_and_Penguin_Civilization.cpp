#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int cur = (1 << n) - 1;
    cout << cur << " ";
    for (int b = n - 1; b >= 0; --b) {
        cur &= ~(1 << b);
        cout << cur << " ";
        vector<int> hb;
        for (int i = b + 1; i < n; ++i) {
            hb.push_back(i);
        }
        int m = 1 << hb.size();
        for (int k = 1; k < m; ++k) {
            int v = cur;
            for (int j = 0; j < (int)hb.size(); ++j) {
                if ((k >> j) & 1) {
                    v |= (1 << hb[j]);
                }
            }
            cout << v << " ";
        }
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}