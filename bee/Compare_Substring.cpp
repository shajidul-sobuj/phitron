#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b;
    while(getline(cin, a) && getline(cin, b))
    {
        cout << a.substr(b);
    }
    return 0;
}