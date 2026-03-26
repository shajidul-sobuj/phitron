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

    vector<ll> a(n);
    ll mx = 0;
    forr(i,0,n)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
        
    
    unordered_set<ll> st;
    bool yes = true;
    for (auto x : a)
    {
        if (x < mx)
        {
            if (st.count(x))
            {
                yes = false;
                break;
            }
            else
                st.insert(x);
        }
    }
    if (yes)
        cout << "Yes\n";
    else
        cout << "No\n";

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