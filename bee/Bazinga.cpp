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
    string a,b;
    cin >> a >> b;
    if (a == b) cout << "De novo!\n";
    else if ((a == "tesoura" && (b == "papel" || b == "lagarto")) || (a == "papel" && (b == "pedra" || b == "Spock")) || (a == "pedra" && (b == "lagarto" || b == "tesoura")) || (a == "lagarto" && (b == "Spock" || b == "papel")) || (a == "Spock" && (b == "tesoura" || b == "pedra")))
    {
        cout << "Bazinga!\n";
    }
    
    else cout << "Raj trapaceou!\n";
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    int i=1;
    while (t--)
    {
        cout << "Caso #" << i << ": ";
        i++;
        boom();
    }

    return 0;
}




