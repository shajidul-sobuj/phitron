#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int g=1;g<=t;g++) {
        char s[1001];
        cin >> s;
        int sz = strlen(s);
        sz = sz/2;
        for (int i=0;i<sz;i+=2) {
            cout << s[i];
        }
        cout << endl;
    }

    return 0;
}