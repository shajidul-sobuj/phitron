#include <stdio.h>
#include <string.h>

int main()
{
    char s1[1001],s2[1001];
    scanf("%s",s1);
    scanf("%s",s2);
    int x,y;
    scanf("%d %d",&x,&y);
    int ls1 = strlen(s1);
    int ls2 = strlen(s2);
    // for (int i=0;i<ls2;i++){
    //     if (i>=x && i<=y){
    //         s1[i+ls1-1]=s2[i];
    //     }
    // }
    // s1[ls1+(y-x+1)]='\0';

    // printf("%s",s1);


    // for (int i=0;i<(ls1+(y));i++){
    //     // if (s1[i]!=' '){
    //         printf("%c",s1[i]);
    //     // }
        
    // }


    for (int j=x;j<=y;j++){
        s1[ls1++]=s2[j];
    }
    int sz = strlen(s1);
    s1[sz]='\0';

    // for (int i = x; i <= y; i++) {
    //     s1[ls1++] = s2[i];
    // }
    // s1[ls1] = '\0';
    printf("%s",s1);
    return 0;
}
