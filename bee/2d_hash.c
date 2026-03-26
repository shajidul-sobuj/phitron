#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i%2==0) {
                if (j%2==0) {
                    printf("# ");
                }else {
                    printf("  ");
                }
            }else {
                if (j%2==0) {
                    printf("  ");
                }else {
                    printf("# ");
                }
            }
                
        }
        printf("\n");
    }
    return 0;
}