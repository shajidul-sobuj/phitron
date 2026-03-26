#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long x) {
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    for (long long i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

int main() {
    long long N, t;
    cin >> N >> t;
    for (long long k = 0; k <= N - 2; k++) {
        long long ticket = t + (k + 1);
        if (isPrime(ticket)) {
            cout << k << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
