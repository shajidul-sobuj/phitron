#include <stdio.h>
#include <string.h>
void fn(int n, int t) 
{
    if (t==n) {
        return;
    }
    char s[100001];
    scanf("%s",s);
    int sz= strlen(s);
    int a[sz];

    for (int i=0;i<sz;i++) {
        a[i]=s[i]-48;
    }
    for (int i=0;i<sz;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    fn(n,t+1);

}
int main()
{
    int n;
    scanf("%d",&n);
    fn(n,0);
    return 0;
}