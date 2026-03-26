#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        long long int n, q;
        cin >> n >> q;

        vector <long long> a(n+1);
        vector <long long> b(n+1);
        for (long long int i=1;i<=n;i++) {
            cin >> a[i];
        }
        for (long long int i=1;i<=n;i++) {
            cin >> b[i];
        }

        vector <long long> mx(n+2,0);
        for (long long int i=n;i>0;i--) {
            mx[i] = max({a[i],b[i],mx[i+1]});
        }
        vector<long long> pref(n+1,0);
        for (long long int i=1;i<=n;i++) {
            pref[i] = pref[i-1]+mx[i];
        }

        while (q--) {
            long long int l, r;
            cin >> l >> r;
            cout << pref[r]-pref[l-1] << " ";
        }
        cout << endl;
        
    }

    return 0;
}
