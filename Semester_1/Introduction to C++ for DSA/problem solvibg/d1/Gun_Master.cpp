#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n,d;
        cin >> n >> d;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        int count = 0;
        int flag=0;
        for (int i=0;i<n;i++) {
            if (a[i]>d && flag==0) {
                flag=1;
                count++;
            }
            if (a[i]<=d && flag==1) {
                flag=0;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}