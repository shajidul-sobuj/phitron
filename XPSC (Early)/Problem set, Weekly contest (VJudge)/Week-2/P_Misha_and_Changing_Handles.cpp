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

    map<string, string> mp;
    while(n--)
    {
        bool br = false;
        string s1,s2;
        cin >> s1 >> s2;
        for (auto [x,y] : mp)
        {
            if (y == s1)
            {
                mp[x] = s2;
                br = true;
                break;
            }
        }
        if (!br)
        {
            mp[s1] = s2;
        }
    }
    cout << mp.size() << endl;
    for (auto [x,y] : mp)
    {
        cout << x << " " << y << endl;
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