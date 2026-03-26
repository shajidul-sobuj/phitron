#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,t;
    cin >> n >> t;
    int a[n];
    int b[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        cin >> b[i];
    }
    int mn=1000000000;
    for (int i=0;i<n;i++) {
        if (b[i]>=t) {
            mn = std :: min(mn,a[i]);
        }
    }
    if (mn<1000000000) {
        cout << mn << endl;
    }else {
        cout << "Bad Luck!\n";
    }
    return 0;
}