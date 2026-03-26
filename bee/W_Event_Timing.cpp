#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        int p,k,d;
        cin >> p >> k >> d;
        int x=p;
        int ck = p+k;
        for (;x<=ck;) {
            x=x+d;
        }
        cout << "Case " << i << ": " << x << endl;
    }

    return 0;
}