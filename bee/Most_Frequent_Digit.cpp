#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    while (cin >> n)
    {
        map<char, ll> mp;
        ll mx = -10;
        char idx;
        for (ll i=0;i<n.size();i++)
        {
            mp[n[i]]++;
        }
        for (auto [x,y] : mp)
        {
            if (y >= mx)
            {
                mx = y;
                idx = x;
            }
        }
        cout << idx << endl;
    }
    return 0;
}