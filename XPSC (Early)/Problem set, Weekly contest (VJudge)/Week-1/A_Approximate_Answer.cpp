#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y,k;
    cin >> x >> y >> k;

    if (x>y && x-y<=k) cout << "Yes\n";
    else if (x<y && y-x<=k) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}