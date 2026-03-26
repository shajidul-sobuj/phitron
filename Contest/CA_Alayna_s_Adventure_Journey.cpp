#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    long long int mx=-10000000;
    for (int i=1;i<=n;i++) {
        long long int x;
        cin >> x;
        mx = std :: max(mx,x);
    }
    cout << mx << endl;


    return 0;
}