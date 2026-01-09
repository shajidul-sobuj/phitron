#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s) {
        if (c == '4' || c == '7') {
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "NO\n";
        return 0;
    }
    while (cnt > 0) {
        int d = cnt % 10;
        if (d != 4 && d != 7) {
            cout << "NO\n";
            return 0;
        }
        cnt = cnt/10;
    }
    cout << "YES\n";

    
    return 0;
}
