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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    // for (int i=0;i<m;i++)
    // {
    //     int count = 0;
    //     for (int j=0;j<n;j++)
    //     {
    //         if (a[j] <= b[i])
    //             count++;
    //     }
    //     cout << count << " ";
    // }
    // cout << endl;

    map<int, int> fr;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        fr[a[i]]++;
    }
    map<int, int> pre;
    for (auto x : fr)
    {
        count += fr[x.first];
        pre[x.first] = count;
    }

    for (int i = 0; i < m; i++)
    {
        auto it = pre.upper_bound(b[i]);
        if (it == pre.begin())
            cout << 0 << " ";
        else
        {
            --it;
            cout << it->second << " ";
        }
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