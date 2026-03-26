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
    // cin.ignore();
    int n;
    cin >> n;
    cin.ignore(); 

    map<int,string, greater<int>> mp;
    while(n--)
    {
        string s;
        getline(cin , s);
        // cout << s << endl;
        string num;
        for (int i=s.size()-1;i>=0;i--)
        {
            if (s[i] == ' ')
            {
                break;
            }
            num.push_back(s[i]);
            s.pop_back();
        }
        reverse(all(num));
        int x = stoi(num);
        // cout << x << endl;
        mp[x] = s;
        // cout << s << endl;
    }
    // reverse(all(mp));
    for (auto [x,y] : mp)
    {
        cout << y << endl;
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