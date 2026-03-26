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

// void boom()
// {
//     ll n,m,q;
//     cin >> n >> m >> q;
//     map<ll, ll> mp;
//     for (ll i=0;i<m;i++)
//     {
//         ll x;
//         cin >> x;
//         mp[x] = x;
//     }

//     while(q--)
//     {
//         ll x;
//         cin >> x;
//         ll l,r;
//         auto it_low = mp.lower_bound(x);
//         if (it_low == mp.begin())
//         {
//             cout << (mp.begin()->second)-1 << endl;
//             continue;
//         }
//         else 
//         {
//             --it_low;
//             l = it_low->second;
//         }

//         auto it_hi = mp.upper_bound(x);
//         if (it_hi == mp.end())
//         {
//             cout << n-(mp.rbegin()->second) << endl;
//             continue;
//         }
//         else 
//         {
//             r = it_hi->second;
//         }
//         ll ans = min(x-l,r-x);
//         cout << ans << endl;
//         // ll ans = min((x-l),(r-x));
//         // (ans < 0) ? cout << -ans << endl : cout << ans << endl;
//     }

// }

void boom()
{
    ll n,m,q;
    cin >> n >> m >> q;
    set<ll> st;
    for (ll i=0;i<m;i++)
    {
        ll x;
        cin >> x;
        st.insert(x);
    }

    while(q--)
    {
        ll x;
        cin >> x;
        ll l,r;
        auto it_low = st.lower_bound(x);
        if (it_low == st.begin())
        {
            cout << (*st.begin())-1 << endl;
            continue;
        }
        else 
        {
            --it_low;
            l = *it_low;
        }

        auto it_hi = st.upper_bound(x);
        if (it_hi == st.end())
        {
            cout << n-(*st.rbegin()) << endl;
            continue;
        }
        else 
        {
            r = *it_hi;
        }
        cout << (r-l)/2 << endl;
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