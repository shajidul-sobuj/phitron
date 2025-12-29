#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int yr = n/365;
    n=n%365;
    int mon = n/30;
    n=n%30;
    cout << yr << " years\n";
    cout << mon << " months\n";
    cout << n << " days\n";
    return 0;
}