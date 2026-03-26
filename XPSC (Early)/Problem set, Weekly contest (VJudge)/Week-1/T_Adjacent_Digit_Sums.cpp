#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x,y;
    cin >> x >> y;
    int dif = x+1-y;
    if (dif>=0 && dif%9==0) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
