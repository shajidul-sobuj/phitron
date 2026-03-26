#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++) {
        int n;
        scanf("%d",&n);
        int a[n];
        for (int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                if (a[i]>a[j]) {
                    int temp = a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        // for (int i=0;i<n;i++) {
        //     printf("%d ",a[i]);
        // }
        int de = a[n-1]-a[0];
        printf("%d\n",de);
    }
    return 0;
}