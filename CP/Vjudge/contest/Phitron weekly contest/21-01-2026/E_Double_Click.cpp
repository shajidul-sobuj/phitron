#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin >> n >> x;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for (int i=0;i<n-1;i++)
    {
        if (a[i+1]-a[i]<=x)
        {
            cout << a[i+1] << endl;
            return 0;
        }
    }
    cout << "-1\n";

    return 0;
}