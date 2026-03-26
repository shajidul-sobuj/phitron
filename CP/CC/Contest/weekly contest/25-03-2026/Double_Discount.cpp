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
    int n,k;
    cin >> n >> k;
    vector<pair<int, int>> p;
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for (int i=0;i<n;i++)
    {
        cin >> b[i];
    }

    for (int i=0;i<n;i++)
    {
        p.push_back({b[i],a[i]});
    }

    sort(all(p), greater<pair<int, int>>());

    set<int> ans;
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            int st,nd;
            if (p[i].second <= p[j].second)
            {
                st = p[i].second;
                nd = p[j].second;
            }
            else
            {
                st = p[j].second;
                nd = p[i].second;
            }

            int total = st + max(nd-100, nd/2);
            if (total <= k)
            {
                ans.insert(p[i].first+p[j].first);
            }
        }
    }
    if (!ans.empty())
    {
        cout << *ans.rbegin() << endl;
    }
    else
    cout << 0 << endl;

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