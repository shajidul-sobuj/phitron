#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long p, i, e, t;
    cin >> p >> i >> e >> t;
    if (t <= i)
        cout << p;
    else
        cout << p + ((t - i + 29) / 30 * e);
    cout << endl;

    return 0;
}