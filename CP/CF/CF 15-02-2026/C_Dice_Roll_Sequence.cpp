#include <bits/stdc++.h>
using namespace std;

void pookie()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> prev(7, INF), cur(7, INF);

    // first position
    for (int x = 1; x <= 6; x++)
        prev[x] = (a[0] != x);

    for (int i = 1; i < n; i++)
    {
        for (int x = 1; x <= 6; x++)
        {
            cur[x] = INF;

            for (int y = 1; y <= 6; y++)
            {
                // adjacent condition
                if (x != y && x + y != 7)
                {
                    cur[x] = min(cur[x],
                                 prev[y] + (a[i] != x));
                }
            }
        }

        prev = cur;
    }

    int ans = INF;
    for (int x = 1; x <= 6; x++)
        ans = min(ans, prev[x]);

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        pookie();
    }

    return 0;
}
