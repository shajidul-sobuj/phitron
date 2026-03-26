#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'

#define forr(i, a, b) for (int i = a; i < b; i++)
#define forb(i, a, b) for (int i = a; i >= b; i--)

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

void boom()
{

    ll n;
    cin >> n;
    map<string, ll> m;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        string temp = s;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (ch != s[0])
            {
                temp[0] = ch;
                ans += m[temp];
            }
        }
        temp = s;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (ch != s[1])
            {
                temp[1] = ch;
                ans += m[temp];
            }
        }
        m[s]++;
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