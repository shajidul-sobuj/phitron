#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char s[10001];
    scanf("%s",s);
    int sz = strlen(s);
    int f[10001];
    for (int i=0;i<10001;i++){
        f[i]=0;
    }
    for (int i=0;i<sz;i++){
        int val = s[i];
        f[val-'a']++;
    }
    char c[24];
    for (int i=0;i<=26;i++){
        c[i]=i+'a';
    }
    for (int i=0;i<26;i++){
        if (f[i]!=0){
        printf("%c - %d\n",c[i],f[i]);
        }
    }
    return 0;
}
