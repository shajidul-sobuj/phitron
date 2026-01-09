#include <bits/stdc++.h>
using namespace std;

int main() {
    int l,a,b;
    cin >> l >> a >> b;
    long long mo = (a+(2*b))%l;
    cout << mo << endl;
    return 0;
}