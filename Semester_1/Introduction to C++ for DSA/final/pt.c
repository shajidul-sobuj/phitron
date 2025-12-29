#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            // if (a[0][j]) {
            //     printf("*");
            // }
            if (a[0][j] || a[i][0] || a[n-1][j] || a[i][n-1]) {
                printf("*");
            
                printf(" ");}else {
            }
        }
        // printf("\n");
    }
    return 0;
}