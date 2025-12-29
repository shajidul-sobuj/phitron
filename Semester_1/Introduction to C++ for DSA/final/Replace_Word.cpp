#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        string s2;
        cin >> s >> s2;
        while(s.find(s2) != -1)
        {
            s.replace(s.find(s2), s2.size(), "#");
        }
        cout << s << endl;
    }

    return 0;
}