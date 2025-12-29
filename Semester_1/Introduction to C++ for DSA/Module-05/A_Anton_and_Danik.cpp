#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sz = s.size();
    int A=0;
    int D=0;
    for (int i=0;i<sz;i++) {
        if (s[i]=='A') A++;
        if (s[i]=='D') D++;
    }
    if (A>D) {
        cout << "Anton\n";
    }else if (A==D) {
        cout << "Friendship\n";
    }else {
        cout << "Danik\n";
    }

    return 0;
}