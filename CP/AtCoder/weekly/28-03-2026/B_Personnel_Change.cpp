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

    map<int, int> mp1;
    map<int, int> mp2;
    for (int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        mp1[x]++;
        mp2[y]++;
    }

    for (int i=1;i<=m;i++)
    {
        cout << mp2[i]-mp1[i] << endl;
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