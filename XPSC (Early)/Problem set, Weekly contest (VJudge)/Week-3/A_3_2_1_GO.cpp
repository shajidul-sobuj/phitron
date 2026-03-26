#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i=n;i>1;i--)
    {
        cout << i << ",";
    }
    cout << 1 << endl;
    return 0;
}