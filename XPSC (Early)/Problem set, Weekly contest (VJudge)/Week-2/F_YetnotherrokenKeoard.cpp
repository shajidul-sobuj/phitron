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
    string s;
    cin >> s;
    vector<pair <int, char>> up;
    vector <pair <int, char>> lo;
    // int idx_C = -1,idx_s = -1;
    for (int i=0;i<s.size();i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') && s[i] != 'b')
        {
            lo.push_back({i, s[i]});
        }
        if ((s[i] >= 'A' && s[i] <= 'Z') && s[i] != 'B')
        {
            up.push_back({i, s[i]});
        }

        // cout << idx_C << " " << idx_s << endl;
        if (s[i] == 'b')
        {
            if (!lo.empty())
            {
               lo.pop_back();
            }
        }
        else if (s[i] == 'B')
        {
             if (!up.empty())
            {
               up.pop_back();
            }
        }
        
    }
    vector<pair<int,char>> ans = up;
    ans.insert(ans.end(), lo.begin(), lo.end());
    sort(ans.begin(),ans.end());
    for (int i=0;i<ans.size();i++)
    {
        cout << ans[i].second;
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