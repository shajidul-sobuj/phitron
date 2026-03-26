#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector <int> a(n);
    int mx = INT_MIN;
    for (int i=0;i<n;i++){
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    int max_count = 0;
    for (int i=0;i<n;i++){
        if (a[i] == mx) max_count++; 
    }
    cout << max_count << "\n";
}
       

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}