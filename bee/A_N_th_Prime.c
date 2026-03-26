#include <stdio.h>
#include <math.h>
long long int fn_2(long long int d) {
    for (long long int k=2;k*k<=d;k++) {
        if (d%k==0) {
            return 0;
        }
    }
    return 1;
}

long long int fn_1(long long int d) {
    for (long long int i=d;;i++ )
        {
            int ck = fn_2(i);
            if (ck==1){
                return i;
            }
        }
}

int main()
{
    long long int a[500000];
    a[0]=2;
    a[1]=3;
    for (int i=2;i<500000;i++) {
        long long int d=a[i-1]+1;
        int out = fn_1(d);
        a[i]=out;
    }
    long long int n;
    scanf("%lld",&n);
    printf("%lld\n",a[n-1]);
    return 0;
}