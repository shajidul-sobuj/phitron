#include <bits/stdc++.h>
using namespace std;

void pookie()
{
    int n,k;
    cin >> n >> k;
    list<int> a;
    for (int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    a.sort();
    k--;
    vector<int> nw;
    while(k--)
    {
        int x = a.front();
        nw.push_back(x);
        a.pop_front();
    }
    nw.push_back(a.back());
    vector <int> ol;
    for (auto x : a)
    {
        ol.push_back(x);
        a.pop_front();
    }
    int nw_max = INT_MIN;
    int nw_min = INT_MAX;
    int ol_max = INT_MIN;
    int ol_min = INT_MAX;
    for (int x : nw)
    {
        nw_max = max(nw_max,x);
        nw_min = min(nw_min,x);
    }

    for (int x : nw)
    {
        ol_max = max(ol_max,x);
        ol_min = min(ol_min,x);
    }

    long long int ans = nw_max+nw_min+ol_max+ol_min;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
        pookie();
    return 0;
}