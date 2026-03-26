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

    ll n,k;
    cin >> n >> k;
    
    vector<ll> a(n+1);
    for (ll i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    map<ll, set<ll>> mp;
    for (ll i=1;i<=n;i++)
    {
        mp[a[i]].insert(i);
    }

    while(k--)
    {
        ll x,y;
        cin >> x >> y;
        auto it = mp.find(x);
        auto jt = mp.find(y);
        if (it == mp.end() || jt == mp.end())
        {
            cout << "NO\n";
            continue;
        }
        auto itx = mp[x].begin();
        auto ity = mp[y].rbegin();
        if (*itx < *ity && (!mp[x].empty() && !mp[y].empty()))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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