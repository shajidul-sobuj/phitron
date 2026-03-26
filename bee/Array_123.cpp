#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        for (int i=0,k=n-1;i<n;i++,k--) {
            for (int j=0,l=n-1;j<n;j++,l--) {
                if (i==l)
                    cout << 2;
                else if (i==j)
                    cout << 1;
                else if (i+j == n-1)
                    cout << 2;
                else
                    cout << 3;
            }
            cout << "\n";
        }
    }
    return 0;
}
