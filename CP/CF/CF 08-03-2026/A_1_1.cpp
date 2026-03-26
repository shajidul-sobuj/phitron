#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'

#define forr(i, a, b) for (int i = a; i < b; i++)
#define forb(i, a, b) for (int i = a; i >= b; i--)

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

void boom()
{
    int n;
    string s;
    cin >> n >> s;
    string mx = s;
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 1; i < n - 1; i++)
        {
            if (mx[i] == '0' && mx[i - 1] == '1' && mx[i + 1] == '1')
            {
                mx[i] = '1';
                changed = true;
            }
        }
    }
    string mn = mx;
    changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 1; i < n - 1; i++)
        {
            if (mn[i] == '1' && mn[i - 1] == '1' && mn[i + 1] == '1')
            {
                mn[i] = '0';
                changed = true;
            }
        }
    }

    int maxVal = count(all(mx), '1');
    int minVal = count(all(mn), '1');

    cout << minVal << " " << maxVal << "\n";
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