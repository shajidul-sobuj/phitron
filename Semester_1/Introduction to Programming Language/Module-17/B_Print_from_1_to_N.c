#include <stdio.h>
void fn(n,i)
{
    printf("%d\n",i);
    if (i==n) {
        return;
    }
    fn(n,i+1);
}
int main()
{
    int n,i=1;
    scanf("%d",&n);
    fn(n,i);
    return 0;
}