#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int M1,M2,D1,D2,outp;
        scanf("%d %d %d",&M1,&M2,&D1);
        D2=(M1*D1)/(M1+M2);
        outp=D1-D2;
        printf("%d\n",outp);
    }
    return 0;
}