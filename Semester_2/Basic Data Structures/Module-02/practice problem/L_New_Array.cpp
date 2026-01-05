#include <bits/stdc++.h>
using namespace std;
void fun()
{
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
    vector <int> v(b,b+n);
    v.insert(v.end(),a,a+n);
    for (int x : v) {
        cout << x << " ";
    }
}
int main() {
    fun();
    return 0;
}