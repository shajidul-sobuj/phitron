#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    if (s == string(n, '0'))
    {
        if (n<=3)
        {
            cout << 1 << endl;
            return;
        }else{
            cout << 2 + (n - 4) / 3 << '\n';
            return;
        }
    }

    long long zero = 0;
    long long one = 0;

    for (long long i = 0; i < n; i++) {
        if (s[i] == '1') {
            one++;
            if (zero > 0) {
                one += max(0LL, (zero ) / 3);
                zero = 0;
            }
        } else {
            zero++;
        }
    }
    if (zero > 0) {
        one += (zero ) / 3;
    }

    cout << one << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
