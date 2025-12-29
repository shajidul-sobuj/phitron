#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,k;
    cin >> n >> k;
    long long sum =0;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            long long dif = abs(a[i]-a[j]);
            sum = sum + dif;
        }
    }
    (sum>=k) ? cout << "DANGER\n" : cout << "SAFE\n";

    return 0;
}