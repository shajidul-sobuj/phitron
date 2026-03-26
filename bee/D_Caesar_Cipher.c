#include <stdio.h>
#include <string.h>
int main()
{

    int n;
    scanf("%d",&n);
    getchar();
    char cr[26];
    cr[0]='a';
    for (int i=1;i<26;i++) {
        cr[i]=cr[i-1]+1;
    }
    char s[101];
    scanf("%[^\n]s",s);
    int sz = strlen(s);
    for (int i=0;i<sz;i++) {
        if (s[i]!=' ') {
            int d = s[i]-'a';
            d = (d-n+26)%26;
            printf("%c",cr[d]);

        }else if (s[i]==' ') {
            printf(" ");
        }
    }
    printf("\n");
    // printf("%c",cr[n-1]);
    return 0;
}
