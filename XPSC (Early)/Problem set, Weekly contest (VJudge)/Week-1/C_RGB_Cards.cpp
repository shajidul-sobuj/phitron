#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    long long x = c+(b*10)+(a*100);
    if (x%4==0) cout << "YES\n";
    else cout << "NO\n";
    // cout << x << endl;
    return 0;
}