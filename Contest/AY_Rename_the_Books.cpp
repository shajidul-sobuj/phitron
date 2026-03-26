#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    cin.ignore();
    for (int g=1;g<=t;g++) {
        char s[10001];
        cin.getline(s,10001);
        int sz = strlen(s);
        for (int i=0;i<sz;i++) {
            if (s[i]!=s[i+1]) {
                cout << s[i];
            }
        }
        cout << endl;
    }

    return 0;
}