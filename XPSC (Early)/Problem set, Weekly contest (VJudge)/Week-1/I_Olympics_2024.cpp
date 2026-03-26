#include <bits/stdc++.h>
using namespace std;

int main() {
    int g,s,b;
    cin >> g >> s >> b;
    int need=0;
    if (g<5) need+=5-g;
    if (s<5) need+=5-s;
    if (b<5) need+=5-b;
    cout << need << endl;
    return 0;
}