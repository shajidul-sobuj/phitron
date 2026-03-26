#include <bits/stdc++.h>
using namespace std;

int main() {
    double x,y;
    while(cin >> x >> y)
    {
        double hight = (x*4)/(y*y*3.14);
        double area = (3.14*(y*y))/4;
        cout << "ALTURA = " << fixed << setprecision(2) <<  hight << endl;
        cout << "AREA = " << fixed << setprecision(2) << area << endl;
    }
    return 0;
}