#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    double x = (double)a / b;

    cout << "floor " << a << " / " << b << " = " << floor(x) << endl;
    cout << "ceil "  << a << " / " << b << " = " << ceil(x)  << endl;
    cout << "round " << a << " / " << b << " = " << round(x) << endl;

    return 0;
}
