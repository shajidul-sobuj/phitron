#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        char s[51];
        scanf("%s",s);
        int sz = strlen(s);
        int n_sz = sz/2;
        for (int j=n_sz-1;j>=0;j--) {
            printf("%c",s[j]);
        }
        printf("\n");
    }
    return 0;
}