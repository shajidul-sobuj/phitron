
#include <bits/stdc++.h>
using namespace std;

void hlw() {
    int n;
    string s;
    cin >> n >> s;

    if (n%2 != 0 && s[0] == 'b') {
        cout << "NO\n";
        return;
    }

    for (int i=(n%2);i+1<n;i+=2) {
        if (s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]) {
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
        hlw();
    }
}