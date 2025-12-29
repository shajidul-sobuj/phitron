#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int sz = s.size();
        int flag=0;
        bool good = false;
        for (int i = 0; i + 2 < (int)s.size(); ++i) {
            if ((s[i]=='0' && s[i+1]=='1' && s[i+2]=='0') ||
                (s[i]=='1' && s[i+1]=='0' && s[i+2]=='1')) {
                good = true;
                break;
            }
        }
        cout << (good ? "Good\n" : "Bad\n");

    }
    return 0;
}