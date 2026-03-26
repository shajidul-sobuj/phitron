#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if ((a <= x && b <= y) || (a <= y && b <= x) || (b <= x && c <= y) || (b <= y && c <= x) || (a <= x && c <= y) || (a <= y && c <= x))
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
