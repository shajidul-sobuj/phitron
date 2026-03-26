#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a, b, n;
    cin >> a >> b >> n;
    long long int ans = min((n*a),(((n/3)*b)+((n%3)*a)));
    cout << ans << endl;
    return 0;
}