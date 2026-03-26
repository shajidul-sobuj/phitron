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
    forr(i,0,n)
        cin >> a[i];
    
    sort(all(a));
    map<int,int> mp;
    for (int i=0;i<n;i++)
    {
        mp[a[i]]++;
    }
    // ll count = 0;
    // stack<int> st;
    // for (auto x : mp)
    // {
    //     if(st.empty())
    //     {
    //         st.push(x.second);
    //     }else
    //     {
    //         int y = st.top();
    //         if (y <= x.second)
    //         {
    //             st.pop();
    //         }
    //         else
    //         {
    //             st.pop();
    //             st.push(y-x.second);
    //         }
    //         st.push(x.second);
    //     }
    //     // cout << x.second << " ";
    //     // break;
    // }
    int mx = INT_MIN;
    // while(!st.empty())
    // {
    //     // cout << st.top() << " ";
    //     if (st.top() > mx)
    //         mx = st.top();
    //     else
    //         st.pop();
    // }
    for (int i=0;i<n;i++)
    {
        mx = max(mx,mp[a[i]]);
    }
    cout << mx << endl;

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