#include <stdio.h>
int main()
{
    int n,count=0;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0,j=n-1;i<j;i++,j--){
        if (a[i]==a[j]){
            count++;
        }
        else{
            printf("NO");
            break;
        }
    }
    if (count==n/2){
        printf("YES");
    }
    return 0;
}


// problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/G