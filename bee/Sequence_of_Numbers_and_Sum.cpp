#include <bits/stdc++.h>
using namespace std;
int main() {
    
    for ( ; ; ) {
        int n,m;
        cin >> n >> m;
        if (n<1 || m<1) {
            break;
        }
        int min = std :: min(m,n);
        int max = std :: max(m,n);
        long long int sum=0;
        for (int i=min;i<=max;i++) {
            sum = sum+i;
            cout << i << " ";
        }
        cout << "Sum=" << sum << endl;
    }
    return 0;
}
