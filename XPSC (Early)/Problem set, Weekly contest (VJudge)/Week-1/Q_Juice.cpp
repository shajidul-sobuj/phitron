#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int a,b,c,x,y,z;
    cin >> a >> b >> c >> x >> y >> z;
    long long int count = 0;
    while(1)
    {
        if (x<a || y<b || z<c) break;
        else{
            count++;
            x = x-a;
            y = y-b;
            z = z-c;
        }
    }
    cout << count << endl;
    return 0;
}