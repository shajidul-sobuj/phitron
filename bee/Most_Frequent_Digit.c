#include <stdio.h>
#include <string.h>

int main()
{
    char s[1001];
    scanf("%s",s);
    int sz = strlen(s);
    int a[sz];
    for (int i=0;i<sz;i++) {
        a[i]=s[i]-48;
    }
    int cnt[9];
    for (int i=0;i<sz;i++) {
        cnt[i]=0;
    }
    for(int i=0;i<sz;i++) {
        cnt[a[i]]++; 
    }
    int max=-100000,idx=0;
    for(int i=0;i<9;i++) {
        if (max<cnt[i]) {
            max=cnt[i];
            idx=i;
        }
    }
    printf("%d\n",idx);
    return 0;
}