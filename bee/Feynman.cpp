#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin >> n)
    {
        if (n == 0) break;
        int ans = n*(n+1)*(2*n+1)/6;
        cout << ans << endl;
    }
    return 0;
}