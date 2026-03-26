#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n,x,k;
        cin >> n >> x >> k;
        if (x<k) 
        {
            cout << ::min((x),(k-x)) << endl;
            continue;
        }
        cout << x%k << endl;
    }
    return 0;
}