#include <bits/stdc++.h>
using namespace std;
void fun ()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    int mn=INT_MAX;
    int mx = INT_MIN;
    for (int i=0;i<n;i++) {
        mn = min(a[i],mn);
        mx = max(a[i],mx);
    }
    cout << mn << " " << mx << endl;
}
int main() {
    fun();
    return 0;
}