#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            string s;
            cin >> s;
            
            int ck_1 = 0;
            for (int i = 0; i + 3 < n; i++) {
                if (s[i] == '2' && s[i+1] == '0' && s[i+2] == '2' && s[i+3] == '5') {
                    ck_1++;
                }
            }
            int ck_2 = n; 
            for (int i = 0; i + 3 < n; i++) {
                int curr = 0;
                if (s[i] != '2') curr++;
                if (s[i+1] != '0') curr++;
                if (s[i+2] != '2') curr++;
                if (s[i+3] != '6') curr++;
                
                if (curr < ck_2) ck_2 = curr;
            }
            
            if (ck_1 < ck_2) cout << ck_1 << "\n";
            else cout << ck_2 << "\n";
        }
    }
    return 0;
}