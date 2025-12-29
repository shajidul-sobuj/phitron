#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for (int ti=1;ti<=t;ti++){
        int n;
        scanf("%d",&n);
        int a[n];
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int sum,min=1000000000;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                sum=a[i]+a[j]-(i+1)+(j+1);
                if (sum<min){
                min=sum;
                }
            }
        }
        printf("%d\n",min);
    }
    return 0;
}


// prblem link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/I