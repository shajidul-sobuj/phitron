#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >>  a[i];
    }
    sort(a,a+n);
    int min=a[0];
    int count=0;
    for (int i=0;i<n;i++) {
        if (a[i]==min) {
            count++;
        }
    }
    (count%2==0) ? cout << "Unlucky\n" : cout << "Lucky\n"; 

    return 0;
}