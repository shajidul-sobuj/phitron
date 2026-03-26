#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define endl '\n'

const int INF = 1e18;
const int MOD = 1e9 + 7;

void yes() { cout << "YES\n"; }
void no()  { cout << "NO\n";  }

void boom()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    ll sum = 0;
    vector<int> l, r;

    for (int i=0;i<n;i++)
    {
        if (i < n/2 && s[i] == 'L')
            r.push_back(i);
        else if (i >= n/2 && s[i] == 'R')
            l.push_back(i);

        if (s[i] == 'L') sum += i;
        else sum += n-i-1;
    }

    sort(all(r), greater<int>());

    for (int k=1;k<=n;k++)
    {
        if (!r.empty() || !l.empty())
        {
            ll val_l = -1, val_r = -1;

            if (!r.empty()) val_r = n-r.back()-1;
            if (!l.empty()) val_l = l.back();

            if (val_r >= val_l && val_r != -1)
            {
                sum -= r.back();
                sum += val_r;
                r.pop_back();
            }
            else if (val_l > val_r && val_l != -1)
            {
                sum -= n-l.back()-1;
                sum += val_l;
                l.pop_back();
            }
        }

        cout << sum << " ";
    }
    cout << endl;
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