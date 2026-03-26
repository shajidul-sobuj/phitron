#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[200];
    while (cin >> s) {
        int up=0;
        int lw=0;
        int dg=0;
        int count=0;
        int sz = strlen(s);
        for (int i=0;i<sz;i++) {
            if (s[i]>='a' && s[i]<='z') {
                lw++;
            }else if (s[i]>='A' && s[i]<='Z') {
                up++;
            }else if (s[i]>='0' && s[i]<='9') {
                dg++;
            }

            if (lw>=1 && up>=1 && dg>=1) {
                count++;
                lw=0;
                up=0;
                dg=0;
            }
        }
        cout << count << endl;
    }

    return 0;
}