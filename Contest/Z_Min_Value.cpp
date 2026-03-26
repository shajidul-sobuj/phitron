#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    int x[m];
    for (int i=0;i<m;i++) {
        cin >> x[i];
    }
    int mn;
    int mx;
    int ans=1000000;
    sort(a,a+n);
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            int re = std :: max(x[i],a[j])-min(x[i],a[j]);
            re = abs(re);
            ans = std :: min(re,ans);
        }
        cout << ans << endl;
    }


    return 0;
}