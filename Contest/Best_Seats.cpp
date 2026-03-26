#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        int mn = 100000000;
        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                int x = a[i]+a[j];
                mn = min(x,mn);
                break;
            }
        }
        cout << mn << endl;

    }

    return 0;
}