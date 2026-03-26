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
    vector<int>a(n);
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    sort(all(a));
    int i;
    int j;
    int k;
    bool yes = false;
    for (i=0;i<n;i++)
    {
        i = i;
        j = i+1;
        k = sz(a)-i-1;
        if (a[i]+a[j] != a[k])
        {
            yes = true;
            break;
        }
    }
    if (yes)
        cout << i+1 << " " << j+1 << " " << k+1 << endl;
    else
        cout << -1 << endl;
    

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