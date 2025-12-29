#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int sz = s.size();
    reverse(s.begin(), s.end());
    for (char c : s) {
        c = tolower(c);
        cout << c;
    }
    return 0;
}