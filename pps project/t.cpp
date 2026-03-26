#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char c : s) {
        if (c=='+') {cout << "-";}
        else {cout << c;}
    }
    return 0;
}
