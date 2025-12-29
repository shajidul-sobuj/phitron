#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int g=1;g<=t;g++) {
        long long int x,y;
        cin >> x >> y;
        long long int ls;
        long long int rs;
        ls = (x*x*x*x)+(y*y*4);
        rs = (4*x*x*y);
        if (ls==rs) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }

    return 0;
}