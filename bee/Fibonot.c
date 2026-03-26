#include <stdio.h>

int main()
{
    int n=100001;
    long long int a[n];
    for (int i=2;i<n;i++) {
        a[0]=1;
        a[1]=1;
        a[i]=a[i-1]+a[i-2];
    }
    
    long long int b[n];
    for (int i=1;i<n;i++) {
        b[0]=4;
        for (int j=0;j<n;j++) {
            if (1) {

            }
        }
    }
    for (int i=0,j=1;i<n,j<=n;i++,j++) {
        for (int k=0;k<n;k++) {
            if (j!=a[k]) {
                b[i]=j;
            }
        }
    }
    for (int i=0;i<10;i++) {
        printf("%lld\n",b[i]);
    }
    return 0; 
}