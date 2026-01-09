#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int count = 0;
        int x = 1;
        while (1) {
            if (x % 3 != 0 && x % 10 != 3) {
                count++;
                if (count == k) {
                    cout << x << endl;
                    break;
                }
            }
            x++;
        }
    }

    
    return 0;
}
