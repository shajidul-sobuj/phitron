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
    ll n,k;
    cin >> n >> k;

    if (k == 0)
    {
        int pos = (0+n)%4;
        (pos == 0) ? cout << "Off\n" : cout << "On\n";
    }
    else
    {
        int pos1 = (1+n)%4;
        int pos2 = (2+n)%4;
        int pos3 = (3+n)%4;

        if ((pos1 == 1 || pos1 == 2 || pos1 == 3) && (pos2 == 1 || pos2 == 2 || pos2 == 3) &&(pos3 == 1 || pos3 == 2 || pos3 == 3))
        {
            cout << "On\n";
        }
        else if (pos1 == 0 && pos2 == 0 && pos3 == 0)
        {
            cout << "Off\n";
        }
        else 
        {
            cout << "Ambiguous\n";
        }
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