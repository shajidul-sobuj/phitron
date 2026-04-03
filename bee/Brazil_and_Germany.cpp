#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double n;
    while (cin >> n)
    {
        if (n == 0) break;
        double b = (n/90);
        double a = ((7*n)/90);
        cout << "Brasil " << (int)floor(b) << " x " << "Alemanha " << (int)ceil(a) << endl;
    }
    
    return 0;
}