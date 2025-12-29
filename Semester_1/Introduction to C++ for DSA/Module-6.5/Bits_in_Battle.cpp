#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        long long int a,b;
        cin >> a >> b;
        long long int xr=0;
        for (long long int i=a;i<=b;i++) {
            xr = xr^i;
        }
        cout << xr << endl;
    }

    return 0;
}