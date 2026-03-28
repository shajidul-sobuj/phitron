#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

string cut(string s)
{
    if (s.size()>10)
    {
        s.erase(s.begin()+10, s.end());
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b,c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    
    cout << a << b << c << endl;
    cout << b << c << a << endl;
    cout << c << a << b << endl;

    cout << cut(a) << cut(b) << cut(c) << endl;
    return 0;
}