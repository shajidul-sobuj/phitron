#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,p;
    cin >> t >> p;
    if (t>=1 && t<=60 && p>=1 && p<=40) {
        if (t+p>=70 && t>=24 && p >= 16) cout << "Perfect Score\n";
        else if (t>=24 && p >= 16) cout << "Passed\n";
        else cout << "Failed\n";
    }
    return 0;
}