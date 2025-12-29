#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    string j="Jessica";
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        if (word==j) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}