#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int t,n;
    cin >> t >> n;
    long long int a[n];
    while(t--)
    {
        for (int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        long long int re = a[n-1]*a[n-2];
        re = abs(re);
        cout << re << endl;
    }

    return 0;
}