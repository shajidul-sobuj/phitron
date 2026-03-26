#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[10001];
    cin >> s;
    int sz = strlen(s);
    int count=0;
    for (int i=0;i<sz;i++) {
        if (s[i]=='U' && s[i+1] == 'U' && s[i+2] == 'D' && s[i+3] == 'D' && s[i+4] == 'L' && s[i+5] == 'R' && s[i+6] == 'L' && s[i+7] == 'R' && s[i+8] == 'B' && s[i+9] == 'A') {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}


// UUDDLRLRBA