#include <stdio.h>

int main()
{
    int x;
    int max=-100000;
    int min=100000;
    for (int i=1;i<=3;i++) {
        scanf("%d",&x);
        if (x>max) {
            max=x;
        }
        if (x<min) {
            min=x;
        }
    }
    printf("%d %d",min,max);
    
    return 0;
}