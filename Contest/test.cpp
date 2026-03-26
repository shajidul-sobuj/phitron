#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i=2;i<n;i++) {
        if (n%i==0) {
            cout << "non-prime\n";
            return 0;
        }
    }
    cout << "prime\n";

    return 0;
}