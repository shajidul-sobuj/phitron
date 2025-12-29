#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >>  a[i];
        }
        int mn = 100000000;
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                int x = a[i]+a[j]+(j+1)-(i+1);
                mn = min(x,mn);
            }
        }
        cout << mn << endl;
    }

    return 0;
}