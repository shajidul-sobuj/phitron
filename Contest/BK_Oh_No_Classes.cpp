#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int g=1;g<=t;g++) {
        int a1,b1,a2,b2,a3,b3;
        cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
        int count=0;
        count = count+b1-a1+1;
        count = count+b2-a2+1;
        count = count+b3-a3+1;
        cout << count << endl;

    }

    return 0;
}