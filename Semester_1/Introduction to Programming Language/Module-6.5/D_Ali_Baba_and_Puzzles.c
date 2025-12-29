#include <stdio.h>
int main()
{
    int a,b,c,r;
    scanf("%d%d%d%d",&a,&b,&c,&r);
    if ((a + b - c == r) || (a + b * c == r) || (a - b + c == r) || (a - b * c == r) ||(a * b + c == r) || (a * b - c == r) ){
        printf("YES");
    }else {
        printf("NO");
    }
    
    return 0;
}


// problem link: https://codeforces.com/group/MWSDmqGsZm/contest/326175/problem/D