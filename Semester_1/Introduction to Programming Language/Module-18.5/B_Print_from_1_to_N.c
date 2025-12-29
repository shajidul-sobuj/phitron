#include <stdio.h>
void fn(int n, int i)
{
    printf("%d\n",i);
    if (i==n) {
        return;
    }
    fn(n,i+1);
}
int main()
{
    int n;
    scanf("%d",&n);
    fn(n,1);
    return 0;
}