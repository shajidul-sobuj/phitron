#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[1001];
    cin.getline(s,1001);
    int x= strlen(s);
    for (int i=0;i<x;i++) {
        if (s[i]!=' ') {
            cout << s[i];
        }
    }
    cout << endl;

    return 0;
}