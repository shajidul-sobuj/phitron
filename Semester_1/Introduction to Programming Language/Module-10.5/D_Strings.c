#include <stdio.h>
#include <string.h>
int main()
{
    char a[11];
    char b[11];
    scanf("%s",a);
    scanf("%s",b);
    int sa = strlen(a);
    int sb = strlen(b);
    printf("%d %d\n",sa,sb);
    printf("%s%s\n",a,b);
    char temp;
    temp = a[0];
    a[0] = b[0];
    b[0] = temp;

    printf("%s %s\n",a,b);
    
 
    return 0;
}


// problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/D