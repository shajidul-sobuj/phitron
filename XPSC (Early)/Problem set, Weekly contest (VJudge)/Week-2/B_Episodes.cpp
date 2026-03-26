#include <bits/stdc++.h>
using namespace std;

void pookie()
{
    int n,k;
    cin >> n >> k;
    long long int ans = n*k;
    long long h = ans/60;
    long long m = ans%60;
    cout << h << " " << m << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        pookie();
    }
    return 0;
}