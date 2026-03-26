#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        int x;
        cin >> x;
        if (x<0) {
            if (x%2==0) {
                cout << "EVEN NEGATIVE\n";
            }else {
                cout << "ODD NEGATIVE\n";
            }
        }else if (x>0) {
             if (x%2==0) {
                cout << "EVEN POSITIVE\n";
            }else {
                cout << "ODD POSITIVE\n";
            }
        }else {
            cout << "NULL\n";
        }
    }

    return 0;
}