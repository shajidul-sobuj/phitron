#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d",&n);
    int a[n];
    int esum=0,osum=0;
    if (n>=1 && n<=100000){
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if (a[i]>0){
            esum = esum + a[i];
        }else {
            osum = osum + a[i];
        }
        }
    }
    
    printf("%d %d",esum,osum);
    
    return 0;
}
