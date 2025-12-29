#include <stdio.h>
int main()
{
    char n,i,m;
    scanf("%c",&n);
    for (i='a';i!='z';){
        m = n+1;
        if(n=='z'){
            printf("a\n");
            break;
        }
        printf("%c\n",m);
        break;
    }
    
    return 0;
}