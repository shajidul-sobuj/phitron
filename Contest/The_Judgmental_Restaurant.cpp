#include <bits/stdc++.h>
using namespace std;
int main() {
    int w,m;
    cin >> w >> m;
    if (w>100) {
        if (m<500) {
            cout << "Salad\n";
        }else if (m>=500) {
            cout << "Fruits\n";
        }
    }else if (w<=100) {
        if (m<500) {
            cout << "Khichuri\n";
        }else if (m>=500) {
            cout << "Biriyani\n";
        }
    }

    return 0;
}