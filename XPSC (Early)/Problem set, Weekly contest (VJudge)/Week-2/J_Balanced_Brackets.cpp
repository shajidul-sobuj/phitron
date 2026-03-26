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
    cin >> s;
    stack<char> st;
    for (int i=0;i<s.size();i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else if(st.top() == '[' && s[i] == ']')
        {
            st.pop();
        }
        else if(st.top() == '{' && s[i] == '}')
        {
            st.pop();
        }
        else if(st.top() == '(' && s[i] == ')')
        {
            st.pop();
        }else
        {
            st.push(s[i]);
        }
    }
    if (st.empty())
    {
        cout << "YES\n";
    }else{
        cout << "NO\n";
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