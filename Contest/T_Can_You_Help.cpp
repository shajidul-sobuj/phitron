#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    char a[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> a[i][j];
        }
    }
    
    int flag;
    int cor=0;
    for (int i=0;i<n;i++) {
        flag =0;
        for (int j=0;j<n;j++) {
            if (a[i][j]=='*'){
                flag++;
            }else if(a[i][j]=='.'){
                flag--;
            }
        }
        if (flag == n) {
            cor=1;
            break;
        }
    }


    int flag2;
    int co2=0;
    for (int i=0;i<n;i++) {
        flag2 =0;
        for (int j=0;j<n;j++) {
            if (a[j][i]=='*'){
                flag2++;
            }else if(a[j][i]=='.'){
                flag2--;
            }
        }
        if (flag2 == n) {
            co2=1;
            break;
        }
    }

    int flag3;
    int cor3=0;
    for (int i=0;i<n;i++) {
        flag3 =0;
        for (int j=0;j<n;j++) {
            if (a[i][j]=='*' && i==j){
                flag3++;
            }else if (a[i][j]=='.' && i==j){
                flag3--;
            }
        }
        if (flag3 == n) {
            cor3=1;
            break;
        }
    }

    int flag4;
    int cor4=0;
    for (int i=0;i<n;i++) {
        flag4 =0;
        for (int j=0;j<n;j++) {
            if (a[i][j]=='*' && i+j == n-1){
                flag4++;
            }else if (a[i][j]=='.' && i+j == n-1){
                flag4--;
            }
        }
        if (flag4 == n) {
            cor4=1;
            break;
        }
    }

    if (cor ==1) {
        cout << n*n << endl;
    }else if (co2==1 || cor3==1 || cor4==1){
        cout << n*n << endl;
    }else {
        cout << "Corrupted Image\n";
    }
    return 0;
}