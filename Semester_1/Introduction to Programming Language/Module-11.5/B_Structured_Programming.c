#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=3;i<=n;i=i+3){
        printf("%d ",i);
    }
    return 0;
}
