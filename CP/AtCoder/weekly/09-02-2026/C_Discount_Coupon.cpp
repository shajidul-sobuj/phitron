#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector <int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    while(k--)
    {
        v.pop_back();
    }
    long long int dis = 0;
    for (int x : v)
    {
        dis+=x;
    }
    cout << dis << endl;
    return 0;
}