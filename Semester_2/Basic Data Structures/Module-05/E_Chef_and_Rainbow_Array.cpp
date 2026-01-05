#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        int flag=1;
        if (v[0]!=1) flag=0;
        for (int i=0,j=n-1;i<=j;i++,j--) {
            if (v[i]!= v[j] || v[i]<1 || v[i]>7) {
                flag = 0;
                break;
            }
        }
        for (int i=1;i<n;i++) {
            if (abs(v[i]-v[i-1])>1) {
                flag = 0;
                break;
            }
        }
        bool found7 = false;
        for (int i=0;i<n;i++) {
            if (v[i]==7) {
                found7 = true;
                break;
            }
        }
        if (!found7) flag = 0;
        if (flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
