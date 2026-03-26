#include <bits/stdc++.h>
using namespace std; 
int main() {
    int r,c;
    cin >> r >> c;
    char a[r][c];
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            cin >> a[i][j];
        }
    }
    // for (int i=0;i<r;i++) {
    //     for (int j=0;j<c;j++) {
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }
    int count = 0;
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            if (a[i][j]=='.') {
                if (i!=0 && i!=r-1 && j!=0 && j!=c-1) {
                    if (a[i-1][j]=='.' && a[i][j-1]=='.' && a[i][j+1]=='.' && a[i+1][j]=='.') {
                        count++;
                    }
                }else if (i==0 && j==0) {
                   if ( a[i][j+1]=='.' && a[i+1][j]=='.') {
                        count++;
                    }
                }else if (i==0 && j==c-1) {
                   if ( a[i][j-1]=='.' && a[i+1][j]=='.') {
                        count++;
                    }
                }else if (i==r-1 && j==0) {
                   if (a[i-1][j]=='.' && a[i][j+1]=='.' ) {
                        count++;
                    }
                }else if (i==r-1 &&j==c-1) {
                   if (a[i-1][j]=='.' && a[i][j-1]=='.') {
                        count++;
                    }
                }else if (i==0) {
                    if (a[i][j-1]=='.' && a[i][j+1]=='.' && a[i+1][j]=='.') {
                        count++;
                    }
                }else if (i==r-1) {
                    if (a[i-1][j]=='.' && a[i][j-1]=='.' && a[i][j+1]=='.') {
                        count++;
                    }
                }else if (j==0) {
                    if (a[i-1][j]=='.' && a[i][j+1]=='.' && a[i+1][j]=='.') {
                        count++;
                    }
                }else if (j==c-1) {
                    if (a[i-1][j]=='.' && a[i][j-1]=='.' && a[i+1][j]=='.') {
                        count++;
                    }
                }
            }
        }
    }
    cout << count << endl;
    
    return 0;
}