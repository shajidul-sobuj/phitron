#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int sz = s.size();
    int count=0;
    for (int i=0;i<sz;i++) {
        if (s[i]=='4' || s[i]=='7') {
            count++;
        }
    }
    if ((count==4 || count==7) ) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
    return 0;
}