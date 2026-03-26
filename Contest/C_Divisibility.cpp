#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        long long int n,a,b;
        cin >> n >> a >> b;
        for (long long j=1;j<n;j++) {
            if (j%a==0 && j%b!=0) {
                cout << j << " ";
            }
        }
        cout << endl;
    }

    return 0;
}