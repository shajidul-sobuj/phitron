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

    map<string, vector<int>> mp;
    for (int i=1;i<=3;i++)
    {
        for (int j=0;j<n;j++)
        {
            string s;
            cin >> s;
            mp[s].push_back(i);
        }
    }


    vector<int> ans(4);
    for (auto [x,y] : mp)
    {
        vector<int> temp = y;
        if (sz(temp) == 1)
        {
            ans[temp[0]] += 3;
        }
        else if (sz(temp) == 2)
        {
            ans[temp[0]] += 1;
            ans[temp[1]] += 1;
        }
    }
    
    
    for (int i=1;i<=3;i++)
    {
        cout << ans[i] << " ";
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