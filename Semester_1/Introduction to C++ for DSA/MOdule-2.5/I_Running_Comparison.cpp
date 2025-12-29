#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int l=1;l<=t;l++) {
        int n;
        cin >> n;
        int a[n];
        int b[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        for (int i=0;i<n;i++) {
            cin >> b[i];
        }
        int count=0;
        for (int i=0;i<n;i++) {
            if (a[i]>=b[i]+200) {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}