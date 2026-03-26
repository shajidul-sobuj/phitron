#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int x,y,z;
        cin >> x >> y >> z;
        x = x*1;
        y = y*2;
        z = z*3;
        cout << (x+y+z)/4 << endl;
    }
    return 0;
}