#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        int sum = a + b;
        printf("%d\n",sum);
    }
    return 0;
}