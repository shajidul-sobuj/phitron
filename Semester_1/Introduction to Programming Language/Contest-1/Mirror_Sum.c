#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    int a[n];
    int b[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    int sum=0;
    for (int i=0,j=n-1;i<n,j>=0;i++,j--){
        sum=a[i]+b[j];
        printf("%d ",sum);
    }
    return 0;
}
