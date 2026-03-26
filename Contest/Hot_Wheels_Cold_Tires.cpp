#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    if (t<20) {
        cout << "Soft\n";
    }else if (t>=20 && t<=30) {
        cout << "Medium\n";
    }else if (t>30) {
        cout << "Hard\n";
    }

    return 0;
}