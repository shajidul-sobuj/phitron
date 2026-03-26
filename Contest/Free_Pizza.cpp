#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    int r=0,c=0;
    cin >> t;
    int count=0;
    for (int i=1;i<=t;i++) {
        int x,y;
        cin >> x >> y;
        if (x==r && y==c) {
            count++;
        }else {
            count=0;
        }
        r=x;
        c=y;
        if (count>=2) {
        break;
        }
    }
    if (count>=2) {
        cout << "Yes\n";
    }else {
        cout << "No\n";
    }

    return 0;
}