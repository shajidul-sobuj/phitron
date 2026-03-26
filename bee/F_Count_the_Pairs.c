#include <stdio.h>
int main() {
    long long int n,k;
    scanf("%lld %lld",&n,&k);
    int a[n];
    for (int i=0;i<n;i++) {
        scanf("%lld",&a[i]) ;
    }
    long long int count = 0 ;
    for (int i=0;i<n-1;i++) {
        for (int j=i;j<n;j++) {
            if (a[i]>a[j]) {
                if (a[i]-a[j] == k) {
                    count++;
                }
            }else {
                if (a[j]-a[i] == k ) {
                    count++;
                }
            }
        }
    }
    printf("%lld",count);

    return 0;
}