#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int boys = 0, girls = 0;
        int entered = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') boys++;
            else girls++;
            entered++;
            if (boys > 2 * girls) {
                break;
            }
        }
        cout << entered << endl;
    }

    return 0;
}
