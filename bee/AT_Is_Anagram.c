#include <stdio.h>
#include <string.h>
int main()
{
    char s1[101];
    char s2[101];
    scanf("%s",s1);
    scanf("%s",s2);
    int sz1 = strlen(s1);
    int sz2 = strlen(s2);
    for (int i=0;i<sz1-1;i++) {
        for (int j=i+1;j<sz1;j++) {
            if (s1[i]>s1[j]) {
                char temp = s1[i];
                s1[i]=s1[j];
                s1[j]=temp;
            }
        }
    }
    for (int i=0;i<sz2-1;i++) {
        for (int j=i+1;j<sz2;j++) {
            if (s2[i]>s2[j]) {
                char temp = s2[i];
                s2[i]=s2[j];
                s2[j]=temp;
            }
        }
    }
    int flag=1;
    for (int i=0;i<sz2-1;i++) {
        if (s1[i]==s2[i]) {
            flag =1;
        }else {
            flag=0;
            break;
        }
    }
    if (flag==1) {
        printf("Yes\n");
    }else {
        printf("No\n");
    }
    // printf("%s\n",s1);
    // printf("%s\n",s2);
    return 0;
}