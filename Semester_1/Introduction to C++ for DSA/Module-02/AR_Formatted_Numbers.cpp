#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[10001];
    cin >> s;
    int sz = strlen(s);
    if (sz%3==0) {
        for (int i=0;i<sz;i++) {
            cout << s[i];
            if ((i+1)%3==0 && i!=sz-1) {
                cout << ',';
            }
        }
    }else {
        int comma = sz/3;
        int ext = 3*comma;
        ext = sz-ext;
        if (ext==1) {
            for (int i=0;i<sz;i++) {
                cout << s[i];
                if (((i)%3==0 && i!=sz-1) || i==0) {
                    cout << ',';
                }
            }
        }else if (ext==2) {
            for (int i=0;i<sz;i++) {
                cout << s[i];
                if ( i==1 || ((i-1)%3==0 && i!=sz-1)) {
                    cout << ',';
                }
            }
        }

    }

    return 0;
}