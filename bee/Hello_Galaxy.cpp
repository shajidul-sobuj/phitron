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
    while(cin >> n)
    {
        if (n == 0) break;

        
        multiset<pair<int, string>> st;
        for (int i=0;i<n;i++)
        {
            string s;
            int a,t;
            cin >> s >> a >> t;
            st.insert({(a-t),s});
        }

        // for (auto x : st)
        // {
        //     cout << x.first << " -> " << x.second << endl;
        // }

        cout << st.begin()->second  << endl;

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