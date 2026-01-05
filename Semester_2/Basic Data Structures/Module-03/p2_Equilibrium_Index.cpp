#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i=0;i<n;i++) {
        cin >> v[i];
    }
    int idx;
    for (int i=1;i<n-1;i++) {
        int l=0;
        int r=0;
        for (int j=0;j<i;j++) {
            l+=v[j];
        }
        for (int j=i+1;j<n;j++) {
            r+=v[j];
        }
        if (l==r) {
            idx=i;
            break;
        }else {
            
        }
    }
    cout << idx << endl;



    return 0;
}