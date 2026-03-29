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
    vector<int> p(n+1);
    for (int i=1;i<=n;i++) 
        cin >> p[i];

    set<int> st;
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && (*st.begin() < i))
        {
            st.erase(st.begin());
        }
        if (!st.empty() && (*st.begin() == i))
            break;
        int next = (st.empty() ? n+1 : *st.begin());
        if (p[i] < next)
        {
            st.insert(p[i]);
            cnt++;
        }
    }
    cout << cnt << endl;
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