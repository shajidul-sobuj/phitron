#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    vector<int> s(n, 0);
    for (int i=1;i<n-1;i++) {
        if (a[i]<a[i-1] && a[i]<a[i+1]) {
            s[i] = 1;
        }
    }
    vector<int> prefix(n);
    prefix[0] = s[0];
    for (int i=1;i<n;i++) {
        prefix[i] = prefix[i-1] + s[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; 
        r--;
        long long sum = 0;
        if (l==0) {
            sum = prefix[r];
        } else {
            sum = prefix[r] - prefix[l-1];
        }
        cout << sum << endl;
    }

    return 0;
}
