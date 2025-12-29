#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        long long int m;
        int a,b,c;
        double x;
        scanf("%lld %d %d %d",&m,&a,&b,&c);
        x=(m*1.0)/(a*b*c*1.0);
        long long int y;
        y=x;
        if (x==y) {
            printf("%lld",y);
        }else
        {
            printf("-1");
        }
        printf("\n");

    }
    return 0;
}