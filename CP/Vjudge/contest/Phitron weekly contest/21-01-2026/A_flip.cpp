#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (char c : s)
    {
        if (c=='0') cout << "1";
        else cout << "0";
    }
    return 0;
}