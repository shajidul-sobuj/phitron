#include <stdio.h>
#include <string.h>
int main()
{
    char s[100001];
    scanf("%s",s);
    for (int i=0;s[i]!='\0';i++) {
        if (s[i]>=65 && s[i]<=90) {
            s[i]=s[i]+32;
            printf("%c",s[i]);
        }
        else if (s[i]>=97 && s[i]<=122) {
            s[i]=s[i]-32;
            printf("%c",s[i]);
        }
        else if (s[i]==',') {
            s[i]=' ';
            printf("%c",s[i]);
        }
    }
    
 
    return 0;
}