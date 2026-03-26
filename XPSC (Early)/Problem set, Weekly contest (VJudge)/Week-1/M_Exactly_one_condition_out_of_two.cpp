#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n%2 == 0 && (n<0 && n%3 == 0)) cout << "NO\n";
    else if (n%2 == 0) cout << "YES\n";
    else if ((n<0 && n%3 == 0)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}