#include <stdio.h>

int main()
{
    long long int x;
    scanf("%lld",&x);
    
    while (x!=EOF){
         printf("%x\n",x);
    }
    
    return 0;
}