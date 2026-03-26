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
    int n,m;
    cin >> n >> m;
    deque<int> d;
    while (m--)
    {
        string s;
        cin >> s;
        if (s == "pushLeft")
        {
            int x;
            cin >> x;
            if ((int)d.size() == n)
            {
                cout << "The queue is full" << endl;
                continue;
            }
            d.push_front(x);
            cout << "Pushed in left: " << x << endl;
        }
        else if (s == "pushRight")
        {
            int x;
            cin >> x;
            if ((int)d.size() == n)
            {
                cout << "The queue is full" << endl;
                continue;
            }
            d.push_back(x);
            cout << "Pushed in right: " << x << endl;
        }
        else if (s == "popLeft")
        {
            if (d.empty())
            {
                cout << "The queue is empty" << endl;
                continue;
            }
            cout << "Popped from left: " << d.front() << endl;
            d.pop_front();
        }
        else if (s == "popRight")
        {
            if (d.empty())
            {
                cout << "The queue is empty" << endl;
                continue;
            }
            cout << "Popped from right: " << d.back() << endl;
            d.pop_back();
        }
    }
    
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    int x = 1;
    while (t--)
    {
        cout << "Case " << x << ":" << endl;
        x++;
        boom();
    }

    return 0;
}