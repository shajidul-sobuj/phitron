#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    int sum_1st=0;
    int sum_2nd=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i==j) {
                sum_1st=sum_1st+a[i][j];
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i+j==n-1) {
                sum_2nd=sum_2nd+a[i][j];
            }
        }
    }
    int re=sum_1st-sum_2nd;
    if (re<0) {
        re=-re;
        printf("%d\n",re);
    }else {
        printf("%d\n",re);
    }
    return 0;
}