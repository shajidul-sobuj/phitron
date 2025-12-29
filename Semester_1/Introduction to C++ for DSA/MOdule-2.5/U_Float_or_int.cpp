#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[1001];
    cin >> s;
    int sz = strlen(s);
    int flag=0;
    int idx;
    for (int i=0;i<sz;i++) {
        if (s[i]=='.') {
            idx=i;
            break;
        }
    }
    for (int j=idx+1;j<sz;j++) {
        if (s[j]=='0') {
            flag=1;
        }else {
            flag=0;
            break;
        }
    }
    if (flag==1) {
        cout << "int ";
        for (int i=0;i<idx;i++) {
            cout << s[i];
        }
        cout << endl;
    }else {
        cout << "float ";
        for (int i=0;i<idx;i++) {
            cout << s[i];
        }
        cout << " 0";
        for (int i=idx;i<sz;i++) {
            cout << s[i];
        }
        cout << endl;
    }

    return 0;
}