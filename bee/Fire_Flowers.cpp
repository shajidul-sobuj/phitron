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
    int r1,x1,y1,r2,x2,y2;
    while(cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2)
    {
        int dx = x1-x2;
        int dy = y1-y2;

        int dist_sq = (dx*dx)+(dy*dy);
        int r_diff = (r1-r2);

        if (r_diff >= 0 && dist_sq <= (r_diff*r_diff))
            cout << "RICO\n";
        else
            cout << "MORTO\n";
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