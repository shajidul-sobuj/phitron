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
    vector<int> c(n), p(n);
    for(int i=0;i<n;i++) 
        cin >> c[i] >> p[i];

    double g = 0.0;
    for(int i=n-1;i>=0;i--){
        double mult = 1.0-p[i]/100.0;
        g = max(g, c[i]+mult*g);
    }

    cout << fixed << setprecision(10) << g << "\n";
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