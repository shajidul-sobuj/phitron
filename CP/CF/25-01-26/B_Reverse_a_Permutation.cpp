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
        int mx = INT_MIN;
        for (int i=0;i<n;i++)
        {
            cin >> a[i];
            mx = max(mx,a[i]);
        }
        if (a[0]!=mx)
        {
            reverse(a,a+n);
        }
        for (int i=0;i<n;i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;

    }
    return 0;
}