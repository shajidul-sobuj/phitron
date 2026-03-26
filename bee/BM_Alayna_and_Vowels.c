#include <stdio.h>
#include <string.h>

int main()
{
    char s[1001];
    scanf("%s",s);
    int voc=0;
    int sz = strlen(s);
    for (int i=0;i<sz;i++) {
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
            voc++;
        }else if (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U') {
            voc++;
        }
    }
    printf("%d\n",voc);
    return 0;
}