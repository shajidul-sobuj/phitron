#include <stdio.h>
long long int fn(int i)
{
    if (i==0) {
        return 1;
    }
    long long int fa = fn(i-1);
    return fa*i;
} 
long long int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int ans = fn(n);
    printf("%lld",ans);
    return 0;
}