#include <stdio.h>
#include <string.h>
int main()
{
    char s[1001];
    char t[1001];
    scanf("%s",s);
    scanf("%s",t);
    int sl = strlen(s);
    int tl = strlen(t);
    printf("%d ",sl);
    printf("%d\n",tl);
    printf("%s ",s);
    printf("%s",t);
}