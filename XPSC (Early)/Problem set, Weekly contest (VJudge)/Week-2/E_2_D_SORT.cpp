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

    vector<pair<ll,ll>> p(n);
    for (int i=0;i<n;i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    sort(all(p), [](const pair<ll,ll>& a, const pair<ll,ll>& b){
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    for (auto [x,y] : p)
    {
        cout << x << " " << y << endl;
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