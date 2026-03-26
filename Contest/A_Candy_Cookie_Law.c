#include <stdio.h>
int main()
{
    int a,b,c,d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (c>=a && d<b){
        printf("Yes\n");
    }else {
        printf("No\n");
    }
    return 0;
}



