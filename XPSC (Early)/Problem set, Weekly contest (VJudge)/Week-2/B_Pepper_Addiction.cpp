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
    int N, M;
    cin >> N >> M;

    vector<long long> C(M + 1), sum(M + 1, 0);

    for (int i = 1; i <= M; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < N; i++) {
        int A;
        long long B;
        cin >> A >> B;
        sum[A] += B;
    }

    long long ans = 0;

    for (int j = 1; j <= M; j++) {
        ans += min(C[j], sum[j]);
    }

    cout << ans << "\n";
    

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