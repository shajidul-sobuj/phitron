#include <stdio.h>
void fn(n,i)
{
    if (i==n) {
        return;
    }
    printf("I love Recursion\n");
    fn(n,i+1);
}
int main()
{
    int n,i=0;
    scanf("%d",&n);
    fn(n,i);
    return 0;
}