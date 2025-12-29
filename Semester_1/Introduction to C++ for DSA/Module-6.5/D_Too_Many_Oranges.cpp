#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int mn = 10 * n;
        int mx = 12 * n;
        if (k >= mn && k <= mx) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
