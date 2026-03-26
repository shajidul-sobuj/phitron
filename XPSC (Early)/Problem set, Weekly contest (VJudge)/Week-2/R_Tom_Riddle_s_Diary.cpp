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

    vector<string> s;
    for (int i=0;i<n;i++)
    {
        string g;
        cin >> g;
        s.push_back(g);
    }
    vector <string> ans;
    for (int i=s.size()-1;i>=0;i--)
    {
        bool yes = false;
        for (int j=i-1;j>=0;j--)
        {
            if (s[i] == s[j])
            {
                ans.push_back("YES");
                yes = true;
                break;
            }
        }
        if (!yes)
            ans.push_back("NO");
    }
    reverse(ans.begin(),ans.end());
    for (auto x : ans)
    {
        cout << x << endl;
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