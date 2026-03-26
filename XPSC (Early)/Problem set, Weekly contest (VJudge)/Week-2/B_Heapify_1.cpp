/*
    -----------------------------------------------------
    |  Author    : Shajidul Islam Sobuj                 |
    |  GitHub    : github.com/shajidul-sobuj            |
    |  CodeForces: shajidul-sobuj                       |
    |  AtCoder   : shajidulsobuj                        |
    |  Language  : C++                                  |
    -----------------------------------------------------
*/
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

    vector<ll> a(n+1);
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (int i=1;i<=n/2;i++)
    {
        int j = i*2;
        if (a[i]>a[j])
        {
            swap(a[i], a[j]);
        }
    }
    for (int i=1;i<n;i++)
    {
        if (a[i]>a[i+1])
        {
            no();
            return;
        }
    }
    yes();
    return;
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