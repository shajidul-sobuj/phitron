#include <stdio.h>
int main()
{
    int n,i,a,b;
    scanf("%d",&n);
    if (n<=99 && n>=10){
        a=n%10;
        n=n/10;
        b=n%10;
        if (a%b==0 || b%a==0){
            printf("YES");
        }else {
            printf("NO");
        }
            
        }
    
    
    return 0;
}






// problem link: https://codeforces.com/group/MWSDmqGsZm/contest/326175/problem/I