#include <stdio.h>
#include <string.h>

int main()
{
    char s[1001];
    scanf("%[^\n]s",s);
    int sp_count=0;
    int sz = strlen(s);
    for (int i=0;i<sz;i++) {
        if (s[i]!=' ' && s[i+1]==' ' && (s[0]!=' ')) {
            sp_count++;
        }
    }
    printf("%d\n",sp_count+1);
    return 0; 
}
