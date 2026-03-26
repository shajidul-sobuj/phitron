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
    ll p,q,r,m;
    cin >> p >> q >> r >> m;
    vector<ll> a;
    vector<ll> b;
    vector<ll> c;

    for (ll i=1;i<=m;i++)
    {
        ll pp = p*i;
        ll qq = q*i;
        ll rr = r*i;
        if (pp <= m) a.push_back(pp);
        if (qq <= m) b.push_back(qq);
        if (rr <= m) c.push_back(rr);
    }

    unordered_map<ll, ll> mp;
    for (auto x : a)
    {
        mp[x]++;
    }
    for (auto x : b)
    {
        mp[x]++;
    }
    for (auto x : c)
    {
        mp[x]++;
    }

    // for (auto [x,y] : mp)
    // {
    //     cout << x << " -> " << y << endl;
    // }

    ll alice = 0;
    ll bob = 0;
    ll crl = 0;

    for (auto x : a)
    {
        ll g = mp[x];
        if (g == 1)
        {
            alice += 6;
        }
        else if (g == 2)
        {
            alice += 3;
        }
        else if (g == 3)
        {
            alice += 2;
        }
    }
    for (auto x : b)
    {
        ll g = mp[x];
        if (g == 1)
        {
            bob += 6;
        }
        else if (g == 2)
        {
            bob += 3;
        }
        else if (g == 3)
        {
            bob += 2;
        }
    }
    for (auto x : c)
    {
        ll g = mp[x];
        if (g == 1)
        {
            crl += 6;
        }
        else if (g == 2)
        {
            crl += 3;
        }
        else if (g == 3)
        {
            crl += 2;
        }
    }

    cout << alice << " " << bob << " " << crl << endl;

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