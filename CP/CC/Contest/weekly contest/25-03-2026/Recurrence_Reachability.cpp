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
    long long n, m;
    cin >> n >> m;

    for (int k = 0; k <= 30; k++)
    {
        long long t = (1LL << k) - 1; // 2^k - 1

        if (t == 0)
        {
            if (m >= 1 && m < n)
            {
                cout << m << " " << m + 1 << endl;
                return;
            }
            continue;
        }

        for (long long x = 1; x <= n; x++)
        {
            if ((m - x) % t != 0) continue;

            long long d = (m - x) / t;
            long long y = x + d;

            if (d > 0 && y <= n)
            {
                cout << x << " " << y << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
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