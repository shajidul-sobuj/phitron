#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    cin >> x;
    int count = 0;
    for (int i=5;i>0;i--) {
        int y = x/i;
        count+=y;
        x = x%i;
    }
    cout << count << endl;
    return 0;
}


// 
