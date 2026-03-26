#include <bits/stdc++.h>
using namespace std;
void is_prime(long long n)
{
    if (n<=1) 
    {
        cout << "NO\n";
        return;
    }
    
    if (n==2) 
    {
        cout << "YES\n";
        return;
    }
    if (n%2==0) {
        cout << "NO\n";
        return;
    }

    for (long long i=3; i*i<=n; i+=2) {
        if (n%i==0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        is_prime(n);
    }
    return 0;
}