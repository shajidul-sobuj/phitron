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
    map<int, int> mp;
    multiset<pair<int, int>> p;
    int i=1;
    while(n--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y;
            cin >> y;
            mp[i] = y;
            p.insert({y, -i});
            i++;
        }
        else if (x == 2)
        {
            pair<int, int> idx;
            idx.first = mp.begin()->first, idx.second = mp.begin()->second;
            cout << idx.first << " ";
            mp.erase(mp.begin());
            p.erase({idx.second, -idx.second});
        }
        else if (x == 3)
        {
            
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