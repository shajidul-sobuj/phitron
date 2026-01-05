#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    if (n==1) {
        cout << "YES\n";
        return 0;
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }
    vector<long long> fix;
    for (int i=0;i<n;i++) {
        long long sum=0;
        bool zero=false;
        for (int j=0;j<m;j++) {
            int x=a[i][j];
            if (x==0) zero = true;
            sum += x;
        }
        if (!zero) {
            fix.push_back(sum);
            }
    }
    for (int i=1;i<fix.size();i++) {
        if (fix[i] != fix[0]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
