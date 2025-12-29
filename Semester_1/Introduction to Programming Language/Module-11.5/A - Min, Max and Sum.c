#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int min=1000000,max=-1000000;
    long long int sum=0;
    for (int i=0;i<n;i++){
        if (a[i]<=min){
            min=a[i];
        }if (a[i]>=max){
            max=a[i];
        }
        sum=sum+a[i];
    }
    printf("%d %d %lld\n",min,max,sum);
    return 0;
}
