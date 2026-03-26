#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> d;
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        d.push_back(x);
    }

    for (auto x : d)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}