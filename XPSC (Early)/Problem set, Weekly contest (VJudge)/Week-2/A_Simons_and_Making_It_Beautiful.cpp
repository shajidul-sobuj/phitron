/*      __________________
        |                |
        |    KzSobuj     |
        |________________|
    Codeforces: https://codeforces.com/profile/shajidul-sobuj
    GitHub: https://github.com/shajidul-sobuj
    Telegram: @KzSobuj 

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define fastio() ios::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fall(i,x) for(int i = 0; i < x; i++)

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif


void solve() {
    
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    if (n > 1) {
        int pos = -1;

        for (int i = 0; i < n; i++) {
            if (p[i] == n) {
                pos = i;
                break;
            }
        }

        if (pos != 0) {
            swap(p[0], p[pos]);
        }
    }

    for (int x : p)
        cout << x << " ";
    cout << endl;

}

int main() {
    fastio();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}