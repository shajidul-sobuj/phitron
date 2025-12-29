#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        long long rooms = 0;
        for (int i=0;i<n;i++) {
            int x;
            cin >> x;
            rooms += (x%2==0) ? x/2 : (x+1)/2;
        }
        cout << rooms << endl;
    }
    return 0;
}