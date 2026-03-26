#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,k;
    cin >> a >> b >> k;
    k = k+0.5;
    int ans = (k/a)*b;
    cout << (int)ans << endl;
    return 0;
}