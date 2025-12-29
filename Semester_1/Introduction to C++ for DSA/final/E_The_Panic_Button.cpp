#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    string r;
    cin >> s >> r;
    long long xr = r.size();
    long long xs = s.size();
    long long count = 0;

    long long i = 0, j = 0;

    while (i < xs && j < xr) {
        if (s[i] != r[j]) {
            cout << "NO\n";
            return 0;
        }

        char c = s[i];
        long long cs = 0, cr = 0;

        while (i < xs && s[i] == c) { cs++; i++; }
        while (j < xr && r[j] == c) { cr++; j++; }

        if (cr < cs) {
            cout << "NO\n";
            return 0;
        }
    }

    if (i == xs && j == xr) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
