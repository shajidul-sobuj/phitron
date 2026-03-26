#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x,y;
    cin >> n >> x >> y;
    int ans = (y/x);
    if (n%ans == 0)
        ans = n/ans;
    else
        ans = (n/ans)+1;
    cout << ans << endl;
    return 0;
}