#include <stdio.h>
int fn(int a[],int n)
{
    int sum=0;
    for (int i=0;i<n;i++) {
        sum = sum + a[i];
    }
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    int sum = fn(a,n);
    printf("%d\n",sum);
    return 0;
}