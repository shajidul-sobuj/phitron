#include <bits/stdc++.h>
using namespace std;
int main() {
    double x;
    cin >> x;
    if (x>=0.0 && x<=5.00) {
        cout << "batash\n";
    }else if (x>5.00 && x<=12.00) {
        cout << "kuddus\n";
    }else if (x>12.00) {
        cout << "palao\n";
    }

    return 0;
}