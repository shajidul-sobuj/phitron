#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    long long ans = 0;
    
    int B = sqrt(n);

    for (int x = 1; x <= B; ++x) {
        for (int j = 1; j <= n; ++j) {
            
            long long dist = x * a[j];
            long long i = j - dist;

            if (i >= 1 && a[i] == x) {
                ans++;
            }
        }
    }

    for (int y = 1; y <= B; ++y) {
        for (int i = 1; i <= n; ++i) {
            if (a[i] <= B) continue;

            
            long long dist = a[i] * y;
            long long j = i + dist;

            if (j <= n && a[j] == y) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
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