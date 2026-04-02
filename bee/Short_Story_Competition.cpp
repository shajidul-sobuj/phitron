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
    int n,l,c;
    while(cin >> n >> l >> c)
    {
        vector<string> vs(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vs[i];
        }

        int lines = 1;
        int current = 0;

        for (int i=0;i<n;i++)
        {
            int len = vs[i].size();
            if (i == 0)
            {
                current = len;
            }
            else
            {
                if (current+1+len <= c)
                {
                    current += 1+len;
                }
                else
                {
                    lines++;
                    current = len;
                }
            }
        }

        int pages = (lines+l-1)/l;

        cout << pages << endl;
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