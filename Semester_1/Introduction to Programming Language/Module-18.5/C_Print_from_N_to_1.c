#include <stdio.h>
void fn(int i) 
{
    if (i==1) {
        printf("%d",i);
    }else {
        printf("%d ",i);
    }
    if (i==1) {
        return;
    }
    fn(i-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    fn(n);
    return 0;
}