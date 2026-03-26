#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int g=1;g<=n;g++) {
        int r,c;
        cin >> r >> c;
        int a[r][c];
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                if (i%2==0) {
                    if (j%2==0) {
                        cout << "*";
                    }else {
                        cout << ".";
                    }
                }else {
                    if (j%2==0) {
                        cout << ".";
                    }else {
                        cout << "*";
                    }
                }
                    
            }
            cout << endl;
    }
    cout << endl;
    }
    return 0;
}
