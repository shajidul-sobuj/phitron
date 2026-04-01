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
    ll l,r;
    cin >> l >> r;
    for (ll i=l;i<=r;i++)
    {
        for (ll j=i+1;j<=r;j++)
        {
            for (ll k=j+1;k<=r;k++)
            {
                if (__gcd(i,j) == 1 && __gcd(j,k) == 1 && __gcd(i,k) != 1)
                {
                    cout << i << " " << j << " " << k << endl;
                    return;
                }
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
    // cin >> t;
    while (t--)
    {
        boom();
    }

    return 0;
}