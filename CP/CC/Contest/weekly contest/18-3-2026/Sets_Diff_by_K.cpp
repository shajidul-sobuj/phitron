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

void yes() { cout << "Yes\n"; }
void no()  { cout << "No\n";  }

void boom()
{
    int n, k;
    cin >> n >> k;

    vector<int> b(n+1);
    forr(i,1,n+1)
        cin >> b[i];

    bool ok = true;

    forr(i,1,n+1){
        if(b[i] == 0) continue;
        forr(j,i+1,n+1){
            if(b[j] == 0) continue;
            if(abs(i-j) <= k) { 
                ok = false; 
                break; 
            }
        }
        if(!ok) break;
    }

    forr(i,1,n+1){
        if(b[i] == 1) continue;
        bool blocked = false;
        forr(j,1,n+1){
            if(b[j] == 1 && abs(i-j) <= k){
                blocked = true;
                break;
            }
        }
        if(!blocked) { 
            ok = false; 
            break; 
        }
    }

    if (ok)
        yes();
    else
        no();
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