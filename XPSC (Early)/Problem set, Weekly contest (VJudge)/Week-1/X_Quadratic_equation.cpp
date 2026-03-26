#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    double d = (b*b)-4*a*c;
    if (d<0) {
        cout << "No roots\n";
        return 0;
    }else if (d == 0)
    {
        int t = (-b)/(2*a);
        cout << "One root: " << t << endl;
        return 0;
    }

    int x = ((-b)-sqrt(d))/(2*a);
    int y = ((-b)+sqrt(d))/(2*a);

    if (x>y) swap(x,y);

    cout << "Two roots: " << x << " " << y << endl;
    return 0;
}