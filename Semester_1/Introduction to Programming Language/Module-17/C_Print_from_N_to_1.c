#include <stdio.h>
void fn(n,i)
{
    
    if (i==0) {
        return;
    }
    if (i!=1) {
        printf("%d ",i);
    } else {
        printf("%d",i);
    }
    fn(n,i-1);
    
}
int main()
{
    int n;
    scanf("%d",&n);
    int i=n;
    fn(n,i);
    return 0;
}