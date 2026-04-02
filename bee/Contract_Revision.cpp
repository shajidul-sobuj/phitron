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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    while (1)
    {
        char n;
        cin >> n;
        if (n == '0') break;
        string s;
        cin >> s;
        string ans;
        for (ll i=0;i<sz(s);i++)
        {
            if (s[i] != n) 
            {
                ans.pb(s[i]);
            }
        }
        string cmp(sz(ans),'0');
        while(1)
        {
            if (sz(ans) == 1)
            {
                break;
            }
            if (ans.front() == '0')
            {
                ans.erase(ans.begin());
            }
            else 
            {
                break;
            }
        }
        if (cmp == ans)
        {
            cout << 0 << endl;
        }
        else 
        {
            cout << ans << endl;
        }
    }

    return 0;
}