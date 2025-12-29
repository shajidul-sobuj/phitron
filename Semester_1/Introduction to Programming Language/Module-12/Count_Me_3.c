#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        char s[10001];
        scanf("%s",s);
        int sz = strlen(s);
        int caco=0,smco=0,dico=0;
        for (int i=0;i<sz;i++){
            if (s[i]>='A' && s[i]<='Z'){
                caco++;
            }else if (s[i]>='a' && s[i]<='z'){
                smco++;
            }else if (s[i]>='0' && s[i]<='9'){
                dico++;
            }
        }
        printf("%d %d %d\n",caco,smco,dico);
    }
    return 0;
}
