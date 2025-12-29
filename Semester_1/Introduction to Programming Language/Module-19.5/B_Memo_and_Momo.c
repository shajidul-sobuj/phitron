#include <stdio.h>

int main()
{
    long long int a, b, k;
    scanf("%lld %lld %lld", &a, &b, &k);
   
        if (a % k == 0)
        {
            if (b % k == 0)
            {
                printf("Both\n");
            }
            else
            {
                printf("Memo\n");
            }
        }
        else if (b % k == 0)
        {
            if (a % k == 0)
            {
                printf("Both\n");
            }
            else
            {
                printf("Momo\n");
            }
        }
        else
        {
            printf("No One\n");
        }
    

    return 0;
}