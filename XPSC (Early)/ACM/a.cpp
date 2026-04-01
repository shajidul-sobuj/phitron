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

    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    vector<int> tc(all(a));
    sort(all(tc));
    vector<int> ans;
    stack<int> st;
    // cout << *tc.rbegin() << endl;
    for (int i=n-1;i>=0;i--)
    {
        if (a.empty())
        {
            break;
        }
        if (a[i] != tc.back()) 
        {
            st.push(a[i]);
            a.pop_back();

        }
        else
        {
            st.push(a[i]);
            a.pop_back();
            tc.pop_back();
            while(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
        }
    }
    for (auto x: ans)
    {
        cout << x << " ";
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