#include <bits/stdc++.h>
using namespace std;

int main() {
    double r,l;
    cin >> r >> l;
    double pi = 3.1415;
    double fr = 4.0/3.0;
    double vol = fr*pi*(r*r*r);
    double ans = l/vol;
    cout << (int)ans << endl;
    return 0;
}