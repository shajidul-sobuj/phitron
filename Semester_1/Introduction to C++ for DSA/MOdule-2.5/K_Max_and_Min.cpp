#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int mx = std :: max(a, max(b,c));
    int mn = std :: min(a, min(b,c));
    cout << mn << " " << mx << endl;

    return 0;
}