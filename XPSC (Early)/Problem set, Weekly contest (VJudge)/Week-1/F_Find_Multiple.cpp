#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int a,b,k;
    cin >> a >> b >> k;
    for (long long int i=a;i<=b;i++)
    {
        if (i%k == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}