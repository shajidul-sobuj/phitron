#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n;
    int a[n];

    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    cin >> m;
    int b[m];
    for (int i=0;i<m;i++) {
        cin >> b[i];
    }
    // for (int i=0;i<n;i++) {
    //     cout << a[i] << endl;
    // }
    // for (int i=0;i<m;i++) {
    //     cout << b[i] <<  endl;
    // }
    
    int flag=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (a[i] == b[j] ) {
                flag =1;
                break;
            }else if (a[i]!=b[j]) {
                flag = 0;
                
            }
        }
        if (flag == 0) {
            cout << a[i] << " ";
        }
    }
    return 0;
}