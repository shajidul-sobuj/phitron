#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        (a[0]==0 && a[n-1]==0) ? cout << "Bob\n" : cout << "Alice\n";
    }
    return 0;
}