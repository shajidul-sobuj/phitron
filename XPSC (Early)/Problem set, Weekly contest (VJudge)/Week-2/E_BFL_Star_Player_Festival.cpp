#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin >> n >> m;
    while(n--)
    {
        vector <int> a(m);
        for (int i=0;i<m;i++) cin >> a[i];
        sort(a.begin(),a.end());
        cout << max((a[0]*a[1]),(a[m-1]*a[m-2])) << endl;
    }
    return 0;
}