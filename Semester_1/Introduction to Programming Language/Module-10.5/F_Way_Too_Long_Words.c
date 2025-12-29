#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        char s[101];
        scanf("%s",s);
        int sz = strlen(s);
        if (sz>10){
            printf("%c%d%c",s[0],sz-2,s[sz-1]);
        }else {
            printf("%s",s);
        }
        printf("\n");
    }

    
    return 0;
}





// problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/F