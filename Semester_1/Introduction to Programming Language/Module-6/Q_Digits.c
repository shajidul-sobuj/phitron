#include <stdio.h>
#include <math.h>
int main()
{
    int n,a,r,re,i,de;
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        scanf("%d",&a);
        if (a==0){
            printf("0\n");
            continue;
        }
        for (;a!=0;){
            re = a%10;
            printf("%d ",re);
            a = a/10;
        }
        printf("\n");
    }
    return 0;
}