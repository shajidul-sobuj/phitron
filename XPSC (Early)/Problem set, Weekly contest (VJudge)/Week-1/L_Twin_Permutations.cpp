#include <bits/stdc++.h>
using namespace std;

void pookie()
{
    int n;
    cin >> n;
    vector <int> a(n);
    int mx = INT_MIN;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    mx = mx+1;
    for (int i=0;i<n;i++)
    {
        cout << (int)(mx-a[i]) << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        pookie();
    }
    return 0;
}