#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        char s[1001];
        cin >> s;
        int sz = strlen(s);
        int flag=0;
        for (int j=0;j<sz;j++) {
            if (s[j] =='a' || s[j] =='e' || s[j] =='i' || s[j] =='o' || s[j] =='u') {
                flag=1;
                break;
            }
        }
        (flag==1) ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}