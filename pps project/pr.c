#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool check(char s[], char ck[])
{
    int sz_s = strlen(s);
    int sz_ck = strlen(ck);
    if (sz_s<sz_ck) return false;
    for (int i=0;i<sz_s;i++) {
        if (s[i]!=ck[i]) {
            return false;
            break;
        }
    }
    return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    char s[n][100];
    for (int i=0;i<n;i++) {
        scanf("%s",s[i]);
    }
    char ck[100];
    scanf("%s",ck);
    int count=0;
    for (int i=0;i<n;i++) {
        if (check(s[i],ck)) {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}