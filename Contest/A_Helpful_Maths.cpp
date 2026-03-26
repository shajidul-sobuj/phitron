#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    // cout << s[0];
    for (int i=0;i<s.size()-1;i++) {
       if (s[i]>='1' && s[i]<='9') {
            cout << s[i];
            cout << "+";
       }
    }
    cout << s[s.size()-1] << endl;
    return 0;
}