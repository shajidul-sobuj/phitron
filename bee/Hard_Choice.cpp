#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b,c;
    cin >> a >> b >> c;
    int x,y,z;
    cin >> x >> y >>z;
    int count = 0;
    if (x>a) count += (x-a);
    if (y>b) count += (y-b);
    if (z>c) count += (z-c);
    cout << count  << endl;
    return 0;
}