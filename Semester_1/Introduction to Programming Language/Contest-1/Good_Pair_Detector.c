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
    int count=0;
    for (int j=0;j<n;j++){
        for (int i=j+1;i<n;i++){
            if ((a[i]%2==0 && a[j]%2!=0 ) || (a[i]%2!=0 && a[j]%2==0)){
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}
