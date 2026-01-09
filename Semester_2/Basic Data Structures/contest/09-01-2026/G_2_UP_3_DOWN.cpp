#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y;
    cin >> x >> y;
    int t = x-y;
    if ((t > 0 && t <= 3) || ((t < 0 && t >= -2))) {
        cout << "Yes\n";
    }else {
        cout << "No\n";
    }
    
    return 0;
}