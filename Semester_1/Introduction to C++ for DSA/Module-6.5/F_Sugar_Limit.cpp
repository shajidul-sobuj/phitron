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
        int b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int re = 0;
        for (int l = 0; l <= 100; l++)
        {
            long long sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (b[i] <= l && a[i] > 0)
                {
                    sum = sum + a[i];
                }
            }
            long long s = sum - l;
            if (s > re)
            {
                re = s;
            }
        }
        cout << re << endl;
    }

    return 0;
}
