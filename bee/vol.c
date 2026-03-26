#include <stdio.h>
int main()
{
    char s[1001];
    scanf("%s",s);
    for (int i=0;i<1000;i++){
        if (s[i]>='a' && s[i]<='z'){
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                printf("%c is Voule\n",s[i]);
                
            }else {
                printf("%c is consonant\n",s[i]);
            }
            break;
        }
        
    }
    return 0;
}