#include <stdio.h>

int main() {
    
    int n,i;
    for (i=1;;i++){
        scanf("%d",&n);
        if (n>=1000 && n<=9999){
           
            if (n==1999){
                printf("Correct\n");
                break;
            } printf("Wrong\n");
        }
    }

    return 0;
}