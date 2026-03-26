#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n][3];
    for (int i=0;i<n;i++) {
        for (int j=0;j<3;j++) {
            cin >> a[i][j];
        }
    }
    int count=0;
    for (int i=0;i<n;i++) {
        int ck=0;
        for (int j=0;j<3;j++) {
            ck+=a[i][j];
        }
        if (ck>=2) count++;
    }
    cout << count << endl;
    return 0;
}