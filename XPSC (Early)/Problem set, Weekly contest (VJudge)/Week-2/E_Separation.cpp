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
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int less = 0, equal = 0, greater = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < x) less++;
        else if (a[i] > x) greater++;
        else equal++;
    }

    if (less > 0 && greater > 0 && equal == 0)
        cout << "No\n";
    else
        cout << "Yes\n";

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