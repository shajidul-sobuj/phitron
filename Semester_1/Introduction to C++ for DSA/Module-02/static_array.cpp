#include <bits/stdc++.h>
using namespace std;
int *p;
int fun() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    p = a;
    return n;
    
}

int main() {
    int n = fun();
    for (int i=0;i<n;i++) {
        cout << p[i] << " ";
    }


    return 0;
}