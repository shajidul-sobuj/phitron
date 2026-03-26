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

    vector<int> v;
    for (int i=1;i<=n;i++)
    {
        v.push_back(i);
    }

    vector<pair<int, int>> p;

    // for (auto x : v)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;    

    vector<int> ans;

    int t = n-1;
    cout << 2 << endl;
    while(t--)
    {

        if (v.size() == 1)
        {
            break;
        }
        int x = v.back();
        v.pop_back();
        int y = v.back();
        v.pop_back();
        cout << x << " " << y << endl;
        int ans = round((x+y*1.0)/2);
        v.push_back(ans);
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