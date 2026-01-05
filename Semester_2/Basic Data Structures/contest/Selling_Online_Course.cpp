#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int x;
    cin >> x;
    if (x==0) {
        cout << 0 << endl;
        return 0;
    }
    long long int com = (500+x-1)/x;
    cout <<  com << endl;
    return 0;
}