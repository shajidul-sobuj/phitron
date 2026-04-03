#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    double res = 0.0;

    for (int i=0; i<n;i++)
    {
        res = 1.0/(6.0+res);
    }

    double ans = 3.0+res;

    cout << fixed << setprecision(10);
    cout << ans << endl;
    return 0;
}