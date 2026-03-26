#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        char s[100];
        cin >> s;
        int n=0;
        int e=0;
        int p=0;
        int a=0;
        int l=0;
        int sz = strlen(s);
        for (int j=0;j<sz;j++) {
            if (s[j]=='n') {
                n++;
            }else if (s[j]=='e') {
                e++;
            }else if (s[j]=='p') {
                p++;
            }else if (s[j]=='a') {
                a++;
            }else if (s[j]=='l') {
                l++;
            }
        }


        if (n>=1 && e>=1 && p>=1 && a>=1 && l>=1) {
            cout << "Maile Nepal banauna sakchhu!!\n";
        }else {
            cout << "Hami sabai milera Nepal Banau hai!!\n";
        }
    }

    return 0;
}

