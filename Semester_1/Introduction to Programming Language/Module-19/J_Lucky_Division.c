#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    if (n%4==0 || n%7 == 0) {
        printf("YES\n");
    }else if (n>10 && n<100) {
        int m=n%10;
        n=n-m;
        if (n==40 || n==70) {
            printf("YES\n");
        }else {
            printf("NO\n");
        }
    }else if (n>100) {
        int m=n%10;
        n=n-m;
        n=n/10;
        n=n%10;
        if (n==4 || n==7) {
            printf("YES\n");
        }else {
            printf("NO\n");
        }
    }
    return 0;
}