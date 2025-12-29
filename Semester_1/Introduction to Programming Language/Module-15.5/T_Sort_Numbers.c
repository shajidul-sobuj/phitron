#include <stdio.h>

void fn()
{
    int n=3;
    int a[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    int b[n];
    for (int i=0;i<n;i++) {
        b[i]=a[i];
    }
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (b[i]>b[j]) {
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    for (int i=0;i<n;i++) {
        printf("%d\n",b[i]);
    }
    printf("\n");
    for (int i=0;i<n;i++) {
        printf("%d\n",a[i]);
    }
}
int main()
{
    fn();
    return 0;
}