#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    if (s[s.size()-1] == 'a' && s[s.size()-2] == 't' && s[s.size()-3] == 'n')
        cout << "Yes\n";
    else 
        cout << "No\n";
    return 0;
}