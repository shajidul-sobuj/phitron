#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[1001];
    cin >> s;
    int sz = strlen(s);
    long long int re=1;
    for (int i=1;i<=sz;i++) {
        re=re*i;
    }
    cout << re << endl;

    return 0;
}