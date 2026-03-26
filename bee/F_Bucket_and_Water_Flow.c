#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int i=1;i<=t;i++) {
        int w,x,y,z,tl;
    scanf("%d %d %d %d",&w,&x,&y,&z);
    tl = (y*z)+w;
    if (x<tl) {
        printf("overFlow\n");
    }else if (x==tl) {
        printf("filled\n");
    }else if (x>tl) {
        printf("Unfilled\n");
    }
    }
    
    return 0;
}