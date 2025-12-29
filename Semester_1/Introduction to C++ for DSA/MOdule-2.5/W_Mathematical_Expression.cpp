#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    long long c;
    char s,e;
    cin >> a >> s >> b >> e >> c;
    if (s=='+') {
        if (a+b==c){
            cout << "Yes\n";
        }else {
            cout << a+b << endl;
        }
    }else if (s=='-' ) {
        if (a-b==c){
            cout << "Yes\n";
        }else {
            cout << a-b << endl;
        }
    }else if (s=='*' ) {
        if (a*b==c){
            cout << "Yes\n";
        }else {
            cout << a*b << endl;
        }
    }else if (s=='/' ) {
        if (a/b==c){
            cout << "Yes\n";
        }else {
            cout << a/b << endl;
        }
    }
    return 0;
}