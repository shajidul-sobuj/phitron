#include <bits/stdc++.h>
using namespace std;

long long int ans(long long int n) {
    long long int sum = 0;
    while (n>0) {
        sum += (n%10);
        n = n/10;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long int x;
        cin >> x;

        int count = 0;
        for (long long int y=x+1;y<=x+81;y++) {
            if (y-ans(y) == x) {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
