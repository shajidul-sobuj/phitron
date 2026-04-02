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
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];

    // sort(all(a));

    // map<int, int> mp;
    // int sum = 0;
    // for (int i=0;i<n;i++) 
    // {
    //     sum += a[i];
    //     mp[sum] = i+1;
    // }

    while(q--)
    {
        int x,y;
        cin >> x >> y;
        vector<int> b(a.begin(), a.begin()+x);
        sort(all(b));

        int sum = 0, cnt = 0;
        for (int v : b)
        {
            if (sum+v <= y)
            {
                sum += v;
                cnt++;
            }
            else break;
        }
        cout << cnt << endl;
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