#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int g=1;g<=t;g++) {
        char s[1001];
        cin >> s;
        int sz = strlen(s);
        int x;
        cin >> x;
        cin.ignore();
        char b[x];
        cin >> b;
        int count=0;
        for (int i=0;i<sz;i++) {
            if (s[i]=='?') {
                count++;
            }
        }
        
        for (int i=0;i<x-1;i++) {
            for (int j=i+1;j<x;j++) {
                if (b[i]>b[j]) {
                    char temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                }
            }
        }
        if (count == x) {
            for (int i=0;i<x;i++) {
                for (int j=0;j<sz;j++) {
                    if (s[j] == '?') {
                        s[j]=b[i];
                        break;
                    }
                }
            }
            cout << s << endl;
        }
        else if (x>count) {
            for (int i=0;i<sz;i++) {
                if (s[i]=='?') {
                    cout << b;
                }else {
                    cout << s[i];
                }
            }
            cout << endl;
        }
    }
    return 0;
}