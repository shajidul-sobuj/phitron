#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,q;
    cin >> n >> q;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    
    sort(a,a+n);
    while (q--) 
    {
        int flag=0;
        int val;
        cin >> val;
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if (a[mid]>val) {r = mid-1;}
            else if (a[mid]<val) {l = mid+1;}
            else {
                flag=1;
                break;
            }
        }
        (flag==1) ? cout << "found\n" : cout << "not found\n";
    }
    return 0;
}