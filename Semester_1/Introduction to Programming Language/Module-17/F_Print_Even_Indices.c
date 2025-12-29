#include <stdio.h>
void fn( int a[],int n,int i)
{
    if (i==n) {
        return;
    }
    fn(a,n,i+1);
    if (i%2==0) {
        if (i!=0) {
            printf("%d ",a[i]);
        }else {
            printf("%d",a[i]);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    fn(a,n,0);
    return 0;
}