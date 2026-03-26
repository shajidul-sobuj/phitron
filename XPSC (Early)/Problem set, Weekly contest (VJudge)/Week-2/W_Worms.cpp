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
    int n;
    cin >> n;

    vector<ll> pre;
    int p;
    cin >> p;
    pre.push_back(p);
    n--;
    while(n--)
    {
        ll x; cin >> x;
        pre.push_back(pre.back()+x);
    }

    int m;
    cin >> m;
    while(m--)
    {
        ll x;
        cin >> x;
        ll ans = upper_bound(all(pre),x-1)-pre.begin();
        cout << ans+1 << endl;
    }
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