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
    while(getline(cin, s))
    {
        vector<string> vs;
        if (s == "*") break;
        char ck = toupper(s[0]);
        // cout << ck << " ";
        bool ok = true;
        for (int i=1;i<sz(s);i++)
        {
            if (s[i] != ' ' && s[i-1] == ' ') 
            {
                char cr = toupper(s[i]);
                if (cr == ck) ok = true;
                else 
                {
                    ok = false;
                    break;
                }
                // cout << cr << " ";
            }
        }
        (ok) ? cout << "Y\n" : cout << "N\n";
        // cout << endl;
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