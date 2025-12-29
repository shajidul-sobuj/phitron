#include <stdio.h>
#include <string.h>
int main()
{
    char a[101];
    char b[101];
    scanf("%s %s",&a,&b);
    int sz = strlen(b);
    for (int i=0;i<=sz;i++){  // i<=sz neoyar karon holo jate null char tao ase and garbej value print na hoy/
        a[i]=b[i];
    }

    printf("%s %s",a,b);
    return 0;
}