#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x:a) {
        cin >> x;
    }
    sort (a.begin(),a.end());
    int ans = max(a[0],a[1]-a[0]);
    cout << ans << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
