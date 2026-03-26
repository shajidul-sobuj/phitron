#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    long long int ans = ((int)(a/x))*y+(a%x)+b;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}