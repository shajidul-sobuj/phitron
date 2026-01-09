#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int a,b,k;
    cin >> a >> b >> k;
    long long int m = a-k;
    long long int n = b+m;
    if (m<0) {
        a = 0;
    }else {
        a = a-k;
    }
    if (n<0) {
        b = 0;
    }else {
        b = b+m;
    }
    cout << a << " " << b << endl;

    
    return 0;
}