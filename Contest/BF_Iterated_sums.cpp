#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int a, b;
    cin >> a >> b;

    long long int re = 0;
    for (long long int i = a; i <= b; i++) {
        re = re + (i * i);
    }
    cout << re << endl;
    return 0;
}
