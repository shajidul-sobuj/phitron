#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int g=1;g<=t;g++) {
        int x;
        scanf("%d",&x);
        x = x*2;
        int total = 5*x;
        printf("%d\n",total);
    }
    // 1
    return 0;
}