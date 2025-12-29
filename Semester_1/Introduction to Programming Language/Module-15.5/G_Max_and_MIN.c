#include <stdio.h>
void fn()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    int max=-100000,min=100000;
    for (int i=0;i<n;i++) {
        if (a[i]>max) {
            max=a[i];
        }
        if (a[i]<min) {
            min=a[i];
        }
    }
    printf("%d %d",min,max);
}
int main()
{
    fn();
    return 0;
}