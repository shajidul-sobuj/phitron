#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        vector <int> v(n);
        int mx = INT_MIN;
        for (int i=0;i<n;i++)
        {
            v[a[i]]++;
            if (mx<v[i])
            {
                mx = v[i];
            }
        }
        for (int i=0;i<n;i++)
        {
            if (mx<v[i])
            {
                mx = v[i];
            }
        }
        sort(a,a+n);
        for (int i=0;i<n;i++)
        {
            if (mx==v[i])
            {
                
            }
        }


    }
    return 0;
}