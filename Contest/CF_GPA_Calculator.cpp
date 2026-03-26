#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int g=1;g<=t;g++) {
        double n;
        cin >> n;
        double count=0;
        for (int i=1;i<=n;i++) {
            double x;
            cin >> x;
            count = count + x;
        }
        double avg = count/n;
        cout << "Case " << g << ": " << setprecision(4) << avg << endl;
    }

    return 0;
}