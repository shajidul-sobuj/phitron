#include <stdio.h>

int sum (int n1, int n2)
{
    int ans =(n1+n2);
    return ans;
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int val=sum(a,b);
    printf("%d",val);
    return 0;
}