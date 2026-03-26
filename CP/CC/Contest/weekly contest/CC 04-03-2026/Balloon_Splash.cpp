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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,y;
    cin >> x >> y;
    if (x>y)
        cout << "Alice\n";
    else if (y>x)
        cout << "Bob\n";
    else    
        cout << "Draw\n";

    return 0;
}