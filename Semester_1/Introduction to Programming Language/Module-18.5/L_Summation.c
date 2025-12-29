#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    long long int sum=0;
    for (int i=0;i<n;i++) {
        sum=sum+a[i];
    }
    printf("%lld",sum);
    return 0;
}