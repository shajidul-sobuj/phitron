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
            cin >> a[i];
        }
        int x = 1^2;
        x = x%100;
        cout << x;
    }

    return 0;
}