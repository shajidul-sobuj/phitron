#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int p_n=6+(n/2);
    int space=p_n-1;
    int stat1=1;
    for (int i=1;i<=p_n;i++) {
        for (int j=1;j<=space;j++) {
            printf(" ");
        }
        for (int j=1;j<=stat1;j++) {
            printf("*");
        }
        printf("\n");
        stat1=stat1+2;
        space--;
    }
    for (int i=1;i<=5;i++) {
        for (int j=1;j<=5;j++) {
            printf(" ");
        }
        for (int j=1;j<=n;j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}