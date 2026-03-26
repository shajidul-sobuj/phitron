#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[101];
    for (;cin.getline(s,101);) {
        // cin.getline(s,10001);
        if (strcmp(s,"the end.")==0) {
            continue;
        }
        int sz = strlen(s);
        for (int i=0;i<sz;i++) {
            if (s[i]=='b') {
                cout << "6";
            }else if (s[i]=='g') {
                cout << "9";
            }else if (s[i]=='l') {
                cout << "1";
            }else if (s[i]=='o') {
                cout << "0";
            }else if (s[i]=='s') {
                cout << "5";
            }else if (s[i]=='z') {
                cout << "2";
            }else {
                cout << s[i];
            }
        }
        cout << endl;
    }

    return 0;
}


//'6', '9', '1', '0', '5' and '2' respectively instead of the letters 'b', 'g', 'l', 'o', 's' and 'z'.