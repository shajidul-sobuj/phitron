#include <stdio.h>
int main()
{
    int n,i;
    int  x,y;
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        scanf("%d %d,&x, &y");
        if (x%y==0){
            printf("%0.2f\n",x/y);
        }else {
            printf("divisao impossivel\n");
        }
    }
    return 0;
}