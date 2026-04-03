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
    string s;
    int s1,s2,b1,b2,a1,a2;
    double total_s1 = 0, total_b1 = 0, total_a1 = 0;
    double total_s2 = 0, total_b2 = 0, total_a2 = 0;

    while(n--)
    {
        cin >> s;
        cin >> s1 >> b1 >> a1;
        cin >> s2 >> b2 >> a2;

        total_s1 += s1;
        total_s2 += s2;
        total_b1 += b1;
        total_b2 += b2;
        total_a1 += a1;
        total_a2 += a2;
    }

    double ans_s, ans_b, ans_a;
    ans_s = ((total_s2*1.0)/(total_s1*1.0))*100.00;
    ans_b = ((total_b2*1.0)/(total_b1*1.0))*100.00;
    ans_a = ((total_a2*1.0)/(total_a1*1.0))*100.00;

    cout << fixed << setprecision(2);
    cout << "Pontos de Saque: " << ans_s << " %.\n";
    cout << "Pontos de Bloqueio: " << ans_b << " %.\n";
    cout << "Pontos de Ataque: " << ans_a << " %.\n";

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