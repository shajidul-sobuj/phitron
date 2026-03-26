#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[100001];
    while (cin >> s)
    {
        int count=0;
        int sz = strlen(s);
        for (int i=0;i<sz;i++) {
            if (s[i]=='a') {
                count++;
            }
        }

        cout << count << endl;
    }
    
    return 0;
}