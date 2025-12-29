#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    int mx = INT_MIN;
    int mn = INT_MAX;
    int mx_idx;
    int mn_idx;

    for (int i=0;i<n;i++) {
        mx = max(mx,a[i]);
        mn = min(mn,a[i]);
        if (a[i]==mx){ mx_idx=i;}
        if (mn==a[i]){ mn_idx=i;}
    }
    swap(a[mx_idx],a[mn_idx]);
    for (int i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}