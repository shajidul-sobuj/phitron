#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    vector <long long int> v(n);
    for (long long int i=0;i<n;i++) {
        cin >> v[i];
    }
    vector <long long int> pre(n);
    pre[0] = v[0];
    for (long long int i=1;i<n;i++) {
        pre[i] = pre[i-1]+v[i];
    }
    for (long long int i=n-1;i>=0;i--) {
        cout << pre[i] << " ";
    }
    cout << endl;
    return 0;
}