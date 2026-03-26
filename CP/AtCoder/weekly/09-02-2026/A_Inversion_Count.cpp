#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    int count = 0;
    for (int i=0;i<n-1;i++) 
    {
        for (int j=i+1;j<n;j++) 
        if (i<j && v[i]>v[j])
        {
            count++;
        }
    }
    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}