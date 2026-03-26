#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k,p;
    cin >> n >> k >> p;
    if (k==0) {
        cout << 0 << endl;
        return;
    }
    int ans;
    if (abs(k)%p==0 && abs(k)/p<=n)
    {
        cout << abs(k)/p << endl;
    }else if (abs(k)%p!=0 && (abs(k)/p)+1<=n)
    {
        cout << (abs(k)/p)+1 << endl;
    }else{
        cout << -1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}