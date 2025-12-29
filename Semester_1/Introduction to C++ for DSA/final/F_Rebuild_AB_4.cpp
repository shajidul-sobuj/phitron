#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long x)
{
    if (x < 1)
        return false;
    if (x == 2)
        return true;
    if (x == 1)
        return true;
    if (x % 2 == 0)
        return false;

    for (long long i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i]))
            count++;
    }
    cout << count << "\n";
    return 0;
}
