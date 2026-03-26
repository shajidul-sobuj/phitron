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
    ll n;
    cin >> n;

    vector <ll> p(n);
    vector <ll> a(n);
    vector <ll> b(n);
    for (ll i=0;i<n;i++)
    {
        cin >> p[i];
    }
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for (ll i=0;i<n;i++)
    {
        cin >> b[i];
    }

    vector<tuple<ll,ll,ll>>t(n);
    for (ll i=0;i<n;i++)
    {
        get<0>(t[i]) = p[i];
        get<1>(t[i]) = a[i];
        get<2>(t[i]) = b[i];
    }

    // sort(all(t));
    sort(all(t), greater<tuple<ll, ll ,ll>>());

    stack<ll> st13;
    stack<ll> st12;
    stack<ll> st23;
    stack<ll> st11;
    stack<ll> st22;
    stack<ll> st33;
    for (auto [x,y,z] : t)
    {
        if ((y == 1 && z == 2) || (y == 2 && z ==1))
        {
            st12.push(x);
        }
        else if ((y == 1 && z == 3) || (y == 3 && z ==1))
        {
            st13.push(x);
        }
        else if ((y == 3 && z == 2) || (y == 2 && z ==3))
        {
            st23.push(x);
        }
        else if ((y == 1 && z == 1))
        {
            st11.push(x);
        }
        else if ((y == 2 && z == 2))
        {
            st22.push(x);
        }
        else if ((y == 3 && z == 3))
        {
            st33.push(x);
        }
    }

    ll m;
    cin >> m;
    while(m--)
    {
        ll x;
        cin >> x;

        if (x == 1)
        {
            if (!st11.empty() && !st12.empty() && !st13.empty())
            {
                if (st11.top() <= st12.top() && st11.top() <= st13.top())
                {
                    cout << st11.top() << " ";
                    st11.pop();
                }
                else if (st12.top() < st11.top() && st12.top() < st13.top())
                {
                    cout << st12.top() << " ";
                    st12.pop();
                }
                else if (st13.top() < st11.top() && st13.top() < st12.top())
                {
                    cout << st13.top() << " ";
                    st13.pop();
                }
                else 
                    cout << -1 << " ";
            }
            else if (!st11.empty() && !st12.empty())
            {
                if (st11.top() <= st12.top())
                {
                    cout << st11.top() << " ";
                    st11.pop();
                }
                else if (st12.top() < st11.top())
                {
                    cout << st12.top() << " ";
                    st12.pop();
                }
                else 
                    cout << -1 << " ";
            }
            else if (!st12.empty() && !st13.empty())
            {
                if (st12.top() <= st13.top())
                {
                    cout << st12.top() << " ";
                    st12.pop();
                }
                else if (st13.top() < st12.top())
                {
                    cout << st13.top() << " ";
                    st13.pop();
                }
                else 
                    cout << -1 << " ";
            }
            else if (!st11.empty() && !st13.empty())
            {
                if (st11.top() <= st13.top())
                {
                    cout << st11.top() << " ";
                    st11.pop();
                }
                else if (st13.top() < st11.top())
                {
                    cout << st13.top() << " ";
                    st13.pop();
                }
                else 
                    cout << -1 << " ";
            }
            else if (!st11.empty())
            {
                
                cout << st11.top() << " ";
                st11.pop();
            }

            else if (!st12.empty())
            {
                
                cout << st12.top() << " ";
                st12.pop();
            }

            else if (!st13.empty())
            {
                
                cout << st13.top() << " ";
                st13.pop();
            }

            else
                cout << -1 << " ";
        }

        else if (x == 2)
        {
            if (!st22.empty() && !st12.empty() && !st23.empty())
            {
                if (st22.top() <= st12.top() && st22.top() <= st23.top())
                {
                    cout << st22.top() << " ";
                    st22.pop();
                }
                else if (st12.top() < st22.top() && st12.top() < st23.top())
                {
                    cout << st12.top() << " ";
                    st12.pop();
                }
                else if (st23.top() < st22.top() && st23.top() < st12.top())
                {
                    cout << st23.top() << " ";
                    st23.pop();
                }
                else 
                    cout << -1 << " ";
            }
            else if (!st22.empty() && !st12.empty())
            {
                if (st22.top() <= st12.top())
                {
                    cout << st22.top() << " ";
                    st22.pop();
                }
                else if (st12.top() < st22.top())
                {
                    cout << st12.top() << " ";
                    st12.pop();
                }
                else 
                    cout << -1 << " ";
            }
            else if (!st12.empty() && !st23.empty())
            {
                if (st12.top() <= st23.top())
                {
                    cout << st12.top() << " ";
                    st12.pop();
                }
                else if (st23.top() < st12.top())
                {
                    cout << st23.top() << " ";
                    st23.pop();
                }
                else 
                    cout << -1 << " ";
            }
            else if (!st22.empty() && !st23.empty())
            {
                if (st22.top() <= st23.top())
                {
                    cout << st22.top() << " ";
                    st22.pop();
                }
                else if (st23.top() < st22.top())
                {
                    cout << st23.top() << " ";
                    st23.pop();
                }
                else 
                    cout << -1 << " ";
            }
            else if (!st22.empty())
            {
                
                cout << st22.top() << " ";
                st22.pop();
            }

            else if (!st12.empty())
            {
                
                cout << st12.top() << " ";
                st12.pop();
            }

            else if (!st23.empty())
            {
                
                cout << st23.top() << " ";
                st23.pop();
            }

            else
                cout << -1 << " ";
        }

        else if ((x == 3))
        {
            if (!st33.empty() && !st13.empty() && !st23.empty())
            {
                if (st33.top() <= st13.top() && st33.top() <= st23.top())
                {
                    cout << st33.top() << " ";
                    st33.pop();
                }
                else if (st13.top() < st33.top() && st13.top() < st23.top())
                {
                    cout << st13.top() << " ";
                    st13.pop();
                }
                else if (st23.top() < st33.top() && st23.top() < st13.top())
                {
                    cout << st23.top() << " ";
                    st23.pop();
                }
                else 
                    cout << -1 << " ";
            }
            else if (!st33.empty() && !st13.empty())
            {
                if (st33.top() <= st13.top())
                {
                    cout << st33.top() << " ";
                    st33.pop();
                }
                else if (st13.top() < st33.top())
                {
                    cout << st13.top() << " ";
                    st13.pop();
                }
                else 
                    cout << -1 << " ";
            }
            else if (!st13.empty() && !st23.empty())
            {
                if (st13.top() <= st23.top())
                {
                    cout << st13.top() << " ";
                    st13.pop();
                }
                else if (st23.top() < st13.top())
                {
                    cout << st23.top() << " ";
                    st23.pop();
                }
                else 
                    cout << -1 << " ";
            }
            else if (!st33.empty() && !st23.empty())
            {
                if (st33.top() <= st23.top())
                {
                    cout << st33.top() << " ";
                    st33.pop();
                }
                else if (st23.top() < st33.top())
                {
                    cout << st23.top() << " ";
                    st23.pop();
                }
                else 
                    cout << -1 << " ";
            }
            else if (!st33.empty())
            {
                
                cout << st33.top() << " ";
                st33.pop();
            }

            else if (!st13.empty())
            {
                
                cout << st13.top() << " ";
                st13.pop();
            }

            else if (!st23.empty())
            {
                
                cout << st23.top() << " ";
                st23.pop();
            }

            else
                cout << -1 << " ";
        }
        else
            cout << -1 << " ";
    }
    cout << endl;
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