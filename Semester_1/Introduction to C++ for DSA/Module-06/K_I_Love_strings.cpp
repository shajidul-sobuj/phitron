#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        string s1,s2;
        cin >> s1 >> s2;
        int ln_s1 = s1.size();
        int ln_s2 = s2.size();
        int ln = min(ln_s1,ln_s2);
        for (int i=0;i<ln;i++) {
            cout << s1[i] << s2[i];
        }
        if (ln_s1>ln) {
            for (int i=ln;i<ln_s1;i++) {
                cout << s1[i];
            }
        }else if (ln_s2>ln) {
            for (int i=ln;i<ln_s2;i++) {
                cout << s2[i];
            }
        }
        cout << endl;

    }

    return 0;
}