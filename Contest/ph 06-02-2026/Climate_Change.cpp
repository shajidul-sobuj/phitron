#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    long long int l = 0;
    long long int r = 0;
    for (long long int x : v) {
        l = l+x;
    }
    int count = 0;
    for (int i=n-1;i>0;i--) {
        r = r+v[i];
        l =l-v[i];
        if (l == r) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
