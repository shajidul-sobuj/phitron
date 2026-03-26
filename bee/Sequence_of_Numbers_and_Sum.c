#include <stdio.h>

int main()
{
    for ( ; ; ) {
        int n,m;
        scanf("%d %d",&n,&m);
        if (n<1 || m<1) {
            break;
        }
        int min;
        int max;
        if (m<n) {
            min = m;
            max = n;
        }else {
            min = n;
            max = m;
        }
        long long int sum=0;
        for (int i=min;i<=max;i++) {
            sum = sum+i;
            printf("%d ",i);
        }
        printf("Sum=%d\n",sum);
    }
    return 0;
}