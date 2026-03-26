#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char s[1001];
        cin >> s;
        int sz = strlen(s);
        int cksp=0;
        for (int j=0;j<sz;j++) {
            if (cksp==2) break;
            for (int k=sz-1;k>0;k--) {
                if (cksp==2) break;
                if (s[j]<s[k] && cksp<2) {
                    std :: swap (s[j],s[k]);
                    cksp++;
                    break;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}