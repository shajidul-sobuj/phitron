#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int g=1;g<=t;g++) {
        int n,x;
        cin >> n >> x;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        int flag =0;
        for (int i=0;i<n-2;i++) {
            for (int j=i+1;j<n-1;j++) {
                for (int k=j+1;k<n;k++) {
                    if (a[i]+a[j]+a[k] == x) {
                        flag=1;
                        break;
                    }
                }
            }
        }
        (flag==1) ? cout << "YES\n" : cout << "NO\n";
        
        
    }

    return 0;
}