#include <stdio.h>
#include <string.h>
int main() {
    char s[1001];
    while (scanf("%s",s)!=EOF) {
        int sum = 0;
        int sz = strlen(s);
        for (int i = 0; i < sz; i++) {
            sum=sum+s[i]-48;
        }
        printf("%d\n",sum);
    }
    return 0;
}
