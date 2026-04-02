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
    string s;
    getline(cin, s);

    stack<char> st;
    for (int i=0;i<sz(s);i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            s[i] = (char)(s[i]+3);
        }

        st.push(s[i]);
    }
    s.clear();
    while(!st.empty())
    {
        s.push_back(st.top());
        st.pop();
    }
    for (int i=0;i<sz(s);i++)
    {
        // if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        // {
            s[i] = (char)(s[i]-1);
        // }
    }
    cout << s << endl;
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        boom();
    }

    return 0;
}