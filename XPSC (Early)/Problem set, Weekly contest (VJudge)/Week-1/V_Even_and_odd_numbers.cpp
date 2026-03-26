#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    bool even = false, odd = false;
    if (!even && (a%2 == 0 || b%2 == 0 || c%2 == 0)) even = true;
    if (!odd && (a%2 != 0 || b%2 != 0 || c%2 != 0)) odd = true;
    if (even && odd) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}