#include <stdio.h>

int main()
{
    int a,b;
    char s;
    scanf("%d %c %d",&a,&s,&b);
    int re;
    if (s=='+') {
        re = a+b;
    }else if (s=='+') {
        re = a-b;
    }else if (s=='*') {
        re = a*b;
    }else if (s=='/') {
        re = a/b;
    }
    printf("%d\n",re);
    return 0;
}