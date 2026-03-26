#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int tdays=a+b;
    int clear_days=7-tdays;
    printf("%d\n",clear_days);
    return 0;
}