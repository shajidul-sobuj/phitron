#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        int n,y,r;
        cin >> n >> y >> r;
        int count = 0;
        count = count + y/2;
        count = count + r/1;
        if (count >=n) {
            cout << n << endl;
        }else if (count < n) {
            cout << count << endl;
        }
    }

    return 0;
}