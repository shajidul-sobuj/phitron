#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    int mx=-100000000;
    for (int i=0;i<n;i++) {
        mx = std :: max(a[i],mx);
    }
    cout << mx << endl;

    return 0;
}