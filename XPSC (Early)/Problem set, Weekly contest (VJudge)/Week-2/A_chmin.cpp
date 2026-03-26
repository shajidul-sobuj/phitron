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
    int n,x;
    cin >> n >> x;

    vector<ll> a(n);
    forr(i,0,n)
        cin >> a[i];
    for (int i=0;i<n;i++)
    {
        if (a[i]<x)
        {
            cout << 1 << endl;
            x = a[i];
        }else
        {
            cout << 0 << endl;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //  cin >> t;
    while (t--)
    {
        boom();
    }

    return 0;
}