#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int m;
    scanf("%d",&m);
    int b[m];
    for (int i=0;i<m;i++){
        scanf("%d",&b[i]);
    } 

    int ab[n+m];
    for (int i=0;i<n;i++){
        ab[i]=a[i];
    }
    for (int i=0,j=n;i<m,j<n+m;i++,j++){
        ab[j]=b[i];
    }


    for (int i=0;i<n+m;i++){
        printf("%d ",ab[i]);
    }

    return 0;
}