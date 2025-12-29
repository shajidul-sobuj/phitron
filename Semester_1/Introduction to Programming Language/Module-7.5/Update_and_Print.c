#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d",&n);
    int a[n];
    if (n>=1 && n<=100000){
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
    }
    int x,v;
    scanf("%d %d",&x, &v);
    for (int i=n-1; i>=0; i--) {
        if (i==x){
            a[i]=v;
        }
        printf("%d ",a[i]);
    }
    
    return 0;
}
