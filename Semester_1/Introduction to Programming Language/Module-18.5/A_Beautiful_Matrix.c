#include <stdio.h>

int main()
{
    int n=5;
    int a[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    int x,y;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (a[i][j]!=0) {
                x=i;
                y=j;
                break;
            }
        }
    }
    int c_r;
    int c_c;
    if (x<=2) {
        c_r=2-x;
    }else {
        c_r=x-2;
    }
    if (y<=2) {
        c_c=2-y;
    }else {
        c_c=y-2;
    }
    int move=c_c+c_r;
    printf("%d\n",move);
    return 0;
}