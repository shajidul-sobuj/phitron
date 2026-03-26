#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        int x;
        scanf("%d",&x);
        // if (x%2==0) {
        //     printf("0\n");
        // }else {
        //     printf("1\n");
        // }
        int sum=0;
        for (int j=1;j<=x;j++) {
            if (j%2!=0) {
                sum= sum+1;
            }else {
                sum= sum-1;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}