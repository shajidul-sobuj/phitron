#include <stdio.h>

int main()
{
    char s[10001];
    scanf("%s",s);
    int a[10] = {0};
    for (int i=0;s[i]!='\0';i++) {
        int d = s[i]-48;
        a[d]++;
    }
    // for (int i=0;i<10;i++) {
    //     printf("%d -> %d\n",i,a[i]);
    // }
    int max=-100000;
    int idx;
    for (int i=0;i<10;i++) {
        if (a[i]>max) {
            max = a[i];
            idx = i;
        }
    }
    printf("%d\n",idx);
    return 0;
}