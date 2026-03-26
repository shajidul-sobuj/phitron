#include <bits/stdc++.h>
using namespace std;

int main() {
    double h,m;
    cin >> h >> m;
    double ans;
    if ((30*h)>(5.5*m))
        ans = (30*h - 5.5*m);
    else   
        ans = (5.5*m - 30*h);
    ans = min(ans,360-ans);
    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}