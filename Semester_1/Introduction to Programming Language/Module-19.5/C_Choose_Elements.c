#include <stdio.h>

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (a[i]<a[j]) {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    long long int sum=0;
    long long int max=-1000000000000000000;
    for (int i=0;i<k;i++) {
        sum=sum+a[i];
        if (sum>max) {
            max=sum;
        }
    }
    if (max>0) {
        printf("%lld\n",max);
    }else {
        printf("0\n");
    }
    return 0;
}