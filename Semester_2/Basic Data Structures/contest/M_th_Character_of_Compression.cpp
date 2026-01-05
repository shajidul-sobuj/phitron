#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int d;
    cin >> d;
    string v;

    for (int i=0;i<s.size();i++) {
        char c = s[i];
        if (s[i+1]>'1' && s[i+1]<='9') {
            int x = s[i+1]-48;
            i++;
            for (int j=1;j<=x;j++) {
                v.push_back(c);
            }
        }else {
            v.push_back(c);
        }
    }
    cout << v[d-1] << endl;
    return 0;
}