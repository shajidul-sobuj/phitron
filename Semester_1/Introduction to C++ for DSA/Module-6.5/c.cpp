#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        int pc = n/5;
        pc = pc+(pc/3)+1;
        cout << pc << endl;
    }

    return 0;
}