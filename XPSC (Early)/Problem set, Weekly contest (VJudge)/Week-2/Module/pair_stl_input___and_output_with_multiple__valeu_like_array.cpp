#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    pair<string,int> std[n];
    for (int i=0;i<n;i++)
    {
        cin >> std[i].first >> std[i].second;
    }

    for (auto [x,y] : std)
    {
        cout << x << " " << y << endl;
    }
    return 0;
}