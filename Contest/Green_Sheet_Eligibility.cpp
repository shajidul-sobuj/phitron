#include <bits/stdc++.h>
using namespace std;
int main() {
    int n=8;
    int flag;
    int a[8];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        if (a[i]>=60) {
            flag =1;
        }else {
            flag=0;
            break;
        }
    }
    (flag==1) ? cout << "Eligible\n" : cout << "Not Eligible\n";
    return 0;
}