#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        char s[1001];
        cin >> s;
        int sz = strlen(s);
        long long int sum=0;
        for (int j=0;j<sz;j++) {
            sum = sum + s[j]-48;
        }
        cout << sum << endl;
    }
    return 0;
}