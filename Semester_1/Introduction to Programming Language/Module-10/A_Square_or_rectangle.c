#include <stdio.h>
#include <string.h>
int main()
{
    int n,w,h;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d", &w,&h);
        if (w==h){
            printf("Square\n");
        }else{
            printf("Rectangle\n");
        }
    }
    return 0;
}









// problem link: https://codeforces.com/group/MWSDmqGsZm/contest/329103/problem/A