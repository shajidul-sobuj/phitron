#include <stdio.h>
int fn(int a[], int n, int max,int i) 
{
    if (i==n) {
        return;
    }
    if (a[i]>max) {
        max=a[i];
    }
    int ans = fn(a,n,max,i+1);
    if (ans>max) {
        max=ans;
    }
    return max;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    int max=-100000000;
    int ans = fn(a,n,max,0);
    printf("%d",ans);
    return 0; 
}