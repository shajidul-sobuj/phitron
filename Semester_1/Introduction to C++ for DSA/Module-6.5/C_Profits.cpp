#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n,x;
        cin >> n >> x;
        long long sum=0;
        int count=0;
        if (x>n) {
            cout << "0\n";
            continue;
        }else {
            for (int i=x;i<=n;i++) {
                sum=sum+i;
                count++;
            }
            cout << sum-(count*x) << endl;
        }
    }

    return 0;
}