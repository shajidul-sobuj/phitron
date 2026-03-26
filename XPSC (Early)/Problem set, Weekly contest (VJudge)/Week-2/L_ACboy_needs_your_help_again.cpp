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

void fifo(int n)
{
    queue<int> q;
    while(n--)
    {
        string s;
        
        cin >> s;
        if (s == "IN")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (s == "OUT")
        {
            if (!q.empty())
            {
                cout << q.front() << endl;
                q.pop();
            }else{
                cout << "None\n";
            }
        }
    }
}

void filo(int n)
{
    stack<int> st;
    while(n--)
    {
        string s;
        cin >> s;
        if (s == "IN")
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (s == "OUT")
        {
            if (!st.empty())
            {
                cout << st.top() << endl;
                st.pop();
            }else{
                cout << "None\n";
            }
        }
    }
}

void boom()
{
    int n;
    string s;
    cin >> n >> s;
    if (s == "FIFO")
    {
        fifo(n);
    }else if (s == "FILO")
    {
        filo(n);
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