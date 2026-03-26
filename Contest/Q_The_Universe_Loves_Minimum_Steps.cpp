#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        int n;
        cin >> n;
        int a[n];
        int mx=0;
        for (int j=0;j<n;j++) {
            cin >> a[j];
            mx = std :: max(mx,abs(a[j]));
        }
        cout << "Case " << i << ": " << mx << endl;

    }

    return 0;
}