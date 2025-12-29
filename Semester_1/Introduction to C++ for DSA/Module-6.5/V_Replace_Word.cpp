#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int sz = s.size();
    for (int i=0;i<sz;i++) {
        if (s[i]=='E' && s[i+1]=='G' && s[i+2]=='Y' && s[i+3]=='P' && s[i+4]=='T' && i!=sz-1) {
           s.replace(i,5," ");
        }
    }
    cout << s << endl;
    return 0;
}

// EGYPT