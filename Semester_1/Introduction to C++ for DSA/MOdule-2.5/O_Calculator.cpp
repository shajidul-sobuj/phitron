#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a,b;
    char s;
    cin >> a >> s >> b;
    long long ans;

    if (s=='+') {
        ans = a+b;
        cout << ans <<  endl;
        return 0;
    }else if (s=='-') {
        ans = a-b;
        cout << ans <<  endl;
        return 0;
    }else if (s=='*') {
        ans = a*b;
        cout << ans <<  endl;
        return 0;
    }else if (s=='/') {
        ans = a/b;
        cout << ans <<  endl;
        return 0;
    }
}