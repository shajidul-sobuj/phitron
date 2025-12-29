#include <stdio.h>
int main()
{
    int a,b,temp;
    a=10;
    b=20;
    temp=a;
    a=b;
    b=temp;
    printf("A = %d\n",a);
    printf("B = %d\n",b);
    printf("Chala ja bhodike\n");
    return 0;
}