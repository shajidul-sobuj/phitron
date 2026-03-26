#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'

#define forr(i,a,b) for(int i=a;i<b;i++)
#define forb(i,a,b) for(int i=a;i>=b;i--)

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void yes() { cout << "YES\n"; }
void no()  { cout << "NO\n";  }

void boom()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    forr(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<int> c(n+1, -1);
    int ans = 0;

    forr(i,1,n+1)
    {
        if (c[i] == -1)
        {
            int c0 = 0, c1 = 0;
            bool ok = true;
            vector<int> q;

            q.pb(i);
            c[i] = 0;
            int h = 0;

            while (h < sz(q))
            {
                int u = q[h++];
                if (c[u] == 0) c0++;
                else c1++;

                for (int v : g[u])
                {
                    if (c[v] == -1)
                    {
                        c[v] = 1 - c[u];
                        q.pb(v);
                    }
                    else if (c[v] == c[u])
                    {
                        ok = false;
                    }
                }
            }

            if (ok)
            {
                ans += max(c0, c1);
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        boom();
    }

    return 0;
}