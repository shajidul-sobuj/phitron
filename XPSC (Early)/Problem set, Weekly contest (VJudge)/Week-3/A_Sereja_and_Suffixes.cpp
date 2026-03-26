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
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    set<int> st;
    map<int, int> mp;
    for (int i=a.size()-1;i>0;i--)
    {
        st.insert(a[i]);
        mp[i] = sz(st);
    }

    while(m--)
    {
        int x;
        cin >> x;
        cout << mp[x] << endl;
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