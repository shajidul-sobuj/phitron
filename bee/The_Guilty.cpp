#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    k--;
    for (int i=k;;)
    {
        if (a[i]-1==i){
            cout << a[i] << endl;
            break;
        }
        else{
            i=a[i]-1;
            // if(i<=n){
            //     i=n-1;
            // }
        }
    }
}

int main() {
    int n;
    while(cin >> n)
    {
        if (n==0) return 0;
        solve(n);
    }
    return 0;
}