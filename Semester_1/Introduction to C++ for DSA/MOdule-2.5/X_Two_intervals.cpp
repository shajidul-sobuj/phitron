#include <bits/stdc++.h>
using namespace std;
int main() {
    int s1,s2,e1,e2;
    cin >> s1 >> e1 >> s2 >> e2;
    if (e1>=s2) {
        if (e1>=e2) {
            cout << s2 << " " << e2 << endl;
        }else {
            cout << s2 << " " << e1 << endl;
        }
        
    }else {
        cout << "-1\n";
    }

    return 0;
}