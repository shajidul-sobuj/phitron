#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    int mx=-1000000000;
    int mn=1000000000;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        mx = std :: max(mx,a[i]);
        mn = std :: min(mn,a[i]);
    }

    cout << mx-mn << endl;

    return 0;
}