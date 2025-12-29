#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[1000001];
    while (cin.getline(s,1000001))
    {
        int sz = strlen(s);
        sort(s,s+sz);
        for (int i=0;i<sz;i++) {
            if (s[i]!=' ') {
                cout << s[i];
            }
        }
        cout << endl;
    }
    

    return 0;
}