#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int c[n];
    int x=n,y=n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        cin >> b[i];
    }
    for (int i=0;i<n;i++) {
        cin >> c[i];
    }
    long long int sum=0;

    for (int i=0;i<n;i++) {
        if (a[i]>a[i+1]) {
            sum+=a[i];
            x=i;
            break;
        }else {
            sum+=a[i];
        }
    }
    for (int i=x+1;i<n;i++) {
        if (b[i]>b[i+1]) {
            y=i;
            sum+=b[i];
            break;
        }else {
            sum+=b[i];
        }
    }
    for (int i=y+1;i<n;i++) {
        sum+=c[i];
    }
    cout << sum << endl;
    return 0;
}