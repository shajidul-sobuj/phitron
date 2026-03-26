#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n[1000]={0};
    int x,t;
    scanf("%d",&x);
    for (int i=0;i<1000;i++){
        
        if (i>=2){
            n[i]=n[i-2]+n[i-1];
        }else if(i==1){
            n[i]=1;
        }
        else {
            n[i]=0;
        }
        printf("n[%d] = %d\n",i,n[i]);
        for (int j=0;j<x;j++){
            scanf("%d",&t);
            
                if (t==i){
                    printf("Fib(%d) = %d\n", t, n[i]);
                }
            
        } 
    }
    
    return 0;
}
