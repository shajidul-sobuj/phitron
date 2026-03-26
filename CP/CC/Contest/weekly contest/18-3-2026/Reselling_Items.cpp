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
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    int buy = 0;
    int sell = 0;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(all(a), greater<int>());
    for (int i=0;i<k;i++)
    {
        if (a[i] >= 5)
        {
            buy += 5;
            sell += a[i];
        }
    }

    for (int i=k;i<n;i++)
    {
        if (a[i] >= 10)
        {
            buy += 10;
            sell += a[i];
        }
    }

    cout << sell-buy << endl;


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