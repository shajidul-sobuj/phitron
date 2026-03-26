#include <stdio.h>
#include <string.h>
int main()
{
    char s[101];
    scanf("%[^\n]s",s);
    int sz = strlen(s);
    int sp_count=0;
    for (int i=0;i<sz;i++) {
        if (s[i]==' ') {
            sp_count++;
        }
    }
    // for (int j=1;j<=sp_count;j++) {
        int idx;
        for (int i=0;i<sz;i++) {
        if (s[i]==' ') {
            idx = i;
        }
        for (int i=idx;i<sz;i++) {
        s[i]=s[i+1];
        }
    }
    // }

    printf("%s",s);
    return 0;
}