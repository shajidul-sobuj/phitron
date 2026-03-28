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

int get(int val)
{
    int retn = 0;
    for (int i=1;i*i<=val;i++)
    {
        if (val%i == 0)
        {
            retn++;
            if (i*i != val)
                retn++;
        }
    }
    return retn;
}

void boom()
{
    int x,y;
    cin >> x >> y;

    if (x == y)
    {
        cout << 1 << endl;
        forr(i,0,y) cout << -1 << " ";
        forr(i,0,x) cout << 1 << " ";
        cout << endl;
    }
    else if (x > y)
    {
        cout << get(x-y)%676767677 << endl;
        forr(i,0,y) cout << -1 << " ";
        forr(i,0,x) cout << 1 << " ";
        cout << endl;
    }
    else
    {
        cout << get(y-x)%676767677 << endl;
        forr(i,0,x) cout << 1 << " ";
        forr(i,0,y) cout << -1 << " ";
        cout << endl;
    }
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