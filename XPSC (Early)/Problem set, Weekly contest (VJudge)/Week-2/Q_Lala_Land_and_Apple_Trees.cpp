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

    deque<pair<int,int>> l,r;
    while(n--)
    {
        int x,y;
        cin >> x >> y;
        if (x > 0)
        {
            r.push_back({x,y});
        }
        else
        {
            l.push_back({x,y});
        }
    }
    sort(all(l));
    sort(all(r));
    int apple = 0;
    bool go_right;
    if (sz(r) > sz(l))
    {
        go_right = true;
    }else
    {
        go_right = false;
    }
    while(1)
    {
        if (go_right)
        {
            if (r.empty())
            {
                cout << apple << endl;
                return;
            }else
            {
                apple += r.front().second;
                r.pop_front();
            }
        }
        else
        {
            if (l.empty())
            {
                cout << apple << endl;
                return;
            }
            else
            {
                apple += l.back().second;
                l.pop_back();
            }
        }
        go_right = !go_right;
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