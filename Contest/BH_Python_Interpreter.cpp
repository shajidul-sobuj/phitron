#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[1001];
    cin.getline(s,1001);
    int sz = strlen(s);
    for (int i=7;i<sz;i++) {
        if (s[i]=='"') {
            break;
        }else {
            cout << s[i];
        }
    }

    return 0;
}