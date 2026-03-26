#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,x,y,z;
    cin >> a >> b >> x >> y >> z;
    if(a>x&& b>y || a>y && b>z || a>z && b>x ||
        b>x&& a>y || b>y && a>z || b>z && a>x){
            cout << "1\n";
        }else{
            cout << "0\n";
        }

    return 0;
}