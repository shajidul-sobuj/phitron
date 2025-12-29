#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        char c;
        cin >> n >> c;
        for (int i=1;i<n;i++) {
            cout << c << " ";
        }
        cout << c << endl;
    }
    return 0;
}