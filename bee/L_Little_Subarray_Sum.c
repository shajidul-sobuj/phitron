#include <stdio.h>

int main()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    int arr[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    int sum=0;
    for ( int i=a;i<=b;i++) {
        sum = sum + arr[i];
    }
    printf("%d\n",sum);
    return 0;
}