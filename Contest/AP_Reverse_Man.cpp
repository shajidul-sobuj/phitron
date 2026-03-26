#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[1001];
    cin.getline(s,1001);
    int sz = strlen(s);
    for (int i=sz-1;i>=0;i--) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}