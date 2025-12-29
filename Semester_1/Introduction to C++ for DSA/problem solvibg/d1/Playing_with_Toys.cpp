#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    int x = n-m;
    (x<0) ? cout << 0 << endl : cout << x << endl;
    return 0;
}