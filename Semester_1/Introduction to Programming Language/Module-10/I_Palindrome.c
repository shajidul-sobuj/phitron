#include <stdio.h>
#include <string.h>
int main()
{
    char s[1001];
    int count=0;
    scanf("%s",s);
    int n = strlen(s);
    for (int i=0,j=n-1;i<j;i++,j--) {
        if (s[i]==s[j]) {
            count++;
        }
    }
    if (count == n/2){
        printf("YES");
    }else {
        printf("NO");
    }
    return 0;
}









// problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/I