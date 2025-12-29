#include <stdio.h>
#include <string.h>
int is_palindrome(char s[])
{
    int sz = strlen (s);
    int count=0;
    for (int i=0,j=sz-1;i<j;i++,j--) {
        if (s[i]==s[j]){
            count++;
        }else {
            break;
        }
    }
    if (count==sz/2) {
        return 1;
    }else {
        return 0;
    }
}
int main()
{
    char s[1001];
    scanf("%s",s);
    int re = is_palindrome(s);
    if (re==1) {
        printf("Palindrome\n");
    }else {
        printf("Not Palindrome\n");
    }
    return 0;
}