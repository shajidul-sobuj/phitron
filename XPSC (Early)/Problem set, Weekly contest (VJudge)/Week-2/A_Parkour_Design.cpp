#include <bits/stdc++.h>
using namespace std;

void hello() {
    long long x, y;
    cin >> x >> y;

    long long val = x-2*y;

    if (val%3 != 0) {
        cout << "NO\n";
        return;
    }

    if (y >= 0) {
        if (x < 2*y) {
            cout << "NO\n";
            return;
        }
    } 
    else {
        if (x < (-4*y)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        hello();
    }
}