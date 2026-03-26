#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    int l=0;
    int u=0;
    for (int i=0;i<n;i++) {
        if (a[i]%2==0) {
            l++;
        }else {
            u++;
        }
    }
    if (l>u) {
        printf("READY FOR BATTLE\n");
    }else {
        printf("NOT READY\n");
    }
    return 0;
}