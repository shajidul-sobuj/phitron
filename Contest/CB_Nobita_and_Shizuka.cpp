#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        char s[10001];
        cin >> s;
        int sz = strlen(s);
        int count=0;
        for (int j=0;j<sz;j++) {
            if (s[j]=='0' && s[j+1]=='1' && j!=0) {
                count++;
            }
        }
        cout << "Case " << i << ": " << count << endl;
    }

    return 0;
}