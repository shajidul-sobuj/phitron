#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int f[26]={0};
    for (char c : s) {
        f[c-'a']++;
    }
    for (char c : s) {
        if (f[c-'a'] == 1) {
            cout << c << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}