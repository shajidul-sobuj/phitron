#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n==1)
    {
        cout << 1 << endl;
        return 0;
    }

    for (int i=1;i<=n;i++) {
        cout << i;
    }
    cout << endl;
    int space = n-2;
    for (int i=2,k=n-1;i<n;i++,k--) {
        cout << i;
        for (int j=1;j<=space;j++) {
            cout << " ";
        }
        cout << k << endl;
    }
    for (int i=n;i>0;i--) {
        cout << i;
    }

    return 0;
}
