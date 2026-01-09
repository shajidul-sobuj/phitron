#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n <= 999) {
        cout << n << endl;
    } else if (n <= 9999) {
        cout << (n / 10) * 10 << endl;
    } else if (n <= 99999) {
        cout << (n / 100) * 100 << endl;
    } else if (n <= 999999) {
        cout << (n / 1000) * 1000 << endl;
    } else if (n <= 9999999) {
        cout << (n / 10000) * 10000 << endl;
    } else if (n <= 99999999) {
        cout << (n / 100000) * 100000 << endl;
    } else {
        cout << (n / 1000000) * 1000000 << endl;
    }

    
    return 0;
}
