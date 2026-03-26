#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        int a,b;
        cin >> a >> b;
        int sum = a+b;
        int dif = a-b;
        cout << "Case " << i << ": " << sum << dif << endl;
    }

    return 0;
}