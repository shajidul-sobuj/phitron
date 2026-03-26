#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        if (a[i]==1971) {
            cout << "Joy Bangla\n";
        }else if (a[i]%2==0 ) {
            cout << "Bangla\n";
        }else {
            cout << "Joy\n";
        }
    }

    return 0;
}