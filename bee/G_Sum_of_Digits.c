#include <stdio.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for (int g=1;g<=t;g++) {
        char s[1000001];
        scanf("%s",s);
        int sz=strlen(s);
        int sum=0;
        for (int i=0;i<sz;i++) {
            sum = sum + s[i]-'0';
        }
        printf("%d\n",sum);
    }
    return 0;
}