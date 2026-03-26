#include <stdio.h>
#include <string.h>

int main()
{
    char s[500];
    scanf("%s",s);
    int sz  = strlen(s);
    for (int i=sz-1;i>=0;i--) {
        printf("%c",s[i]);
    }
    return 0;
}