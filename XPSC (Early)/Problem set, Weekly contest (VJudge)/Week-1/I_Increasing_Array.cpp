#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i=0;i<n;i++) cin >> a[i];
    long long int move = 0;
    for (long long int i=0;i<n-1;i++)
    {
        if (a[i]>a[i+1])
        {
            long long int x = a[i]-a[i+1];
            move += x;
            a[i+1] += x;
        }
    }
    // for (long long int x : a)
    // {
    //     cout << x << " ";
    // }
    cout << move << endl;
    return 0;
}