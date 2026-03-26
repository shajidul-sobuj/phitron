#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    long long int count=1;
    long long int i=2;
    if (n==1) {
        cout << i << endl;
        return 0;
    }
    int flag=1;
    for (i=3;;i++) {
        flag=1;
        for (long long int j=2;j<i;j++) {
            if (i%j==0) {
                flag=0;
                break;
            }
        }
        if (flag == 1) {
            count++;
        }
        if (count==n) {
            break;
        }
    }
    cout << i << endl;

    return 0;
}