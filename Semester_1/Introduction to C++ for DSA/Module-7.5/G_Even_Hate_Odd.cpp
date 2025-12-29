#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int e = 0, o = 0;
        if (n % 2 != 0)
        {
            cout << "-1\n";
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] % 2 == 0)
                {
                    e++;
                }
                else if (a[i] % 2 != 0)
                {
                    o++;
                }
            }
            if (e == n || o == n)
            {
                cout << n / 2 << endl;
            }
            else
            {
                (e<o) ? cout << ((n/2)-e) << endl : cout << ((n/2)-o) << endl;
            }
        }
    }
    return 0;
}