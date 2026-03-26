#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    int t=3;
    vector <int> v;
    v = a;
    sort(v.begin(),v.end());
    for (int i=1;i<=n;i++){
        if (a[i]==v[1]) {
            cout << i << " ";
            break;
        }
    }
    for (int i=1;i<=n;i++){
        if (a[i]==v[2]) {
            cout << i << " ";
            break;
        }
    }
    for (int i=1;i<=n;i++){
        if (a[i]==v[3]) {
            cout << i << " ";
            break;
        }
    }
    return 0;
}