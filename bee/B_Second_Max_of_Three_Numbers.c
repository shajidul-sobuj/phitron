#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int g=1;g<=t;g++) {
        int a[3];
        for (int i=0;i<3;i++) {
            scanf("%d",&a[i]);
        }
        for (int i=0;i<3-1;i++) {
            for (int j=i+1;j<3;j++) {
                if (a[i]>a[j]) {
                    int temp = a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        printf("%d\n",a[1]);
    }
    return 0;
}