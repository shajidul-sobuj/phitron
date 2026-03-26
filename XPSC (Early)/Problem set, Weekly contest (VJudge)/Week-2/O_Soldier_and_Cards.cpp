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

    int k1,k2;
    cin >> k1;
    deque<int> a(k1);
    for (int i=0;i<k1;i++)
        cin >> a[i];

    cin >> k2;
    deque<int> b(k2);
    for (int i=0;i<k2;i++)
        cin >> b[i];
    
    int count = 0;
    int ck = 1000;
    while(ck--)
    {
        if (a.empty())
        {
            cout << count << " " << 2 << endl;
            return;
        }
        else if (b.empty())
        {
            cout << count << " " << 1 << endl;
            return;
        }
        // else
        // {
        //     cout << -1 << endl;
        //     break;
        // }

        int x = a.front();
        a.pop_front();
        int y = b.front();
        b.pop_front();
        if (x > y)
        {
            a.push_back(y);
            a.push_back(x);
        }else if (x < y)
        {
            b.push_back(x);
            b.push_back(y);
        }
        count++;
    }
    cout << -1 << endl;
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