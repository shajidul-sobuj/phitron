#include <bits/stdc++.h>
using namespace std;
int main() {
    char a[1001];
    char b[1001];
    cin >> a >> b;
    int sza = strlen(a);
    int szb = strlen(b);
    int count=0;
    for (int i=0;i<sza;i++) {
        for (int j=0;j<szb;j++) {
            if (a[i]==b[j]) {
                count++;
            }
        }
    }
    if (count == sza) {
        cout << "Yes\n";
    }else {
        cout << "No\n";
    }

    return 0;
}