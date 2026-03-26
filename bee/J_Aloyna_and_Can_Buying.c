#include <stdio.h>

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int l=k+1;
    int a[l];
    for (int i=0;i<l;i++) {
        a[i]=0;
    }
    int arr[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<n;i++) {
        int x=arr[i];
        a[x]++;
    }
    int max = -10000;
    int max_idx;
    int min = 10000;
    int min_idx;
    for (int i=0;i<l;i++) {
        if (a[i]!=0) {
            if (a[i]>max) {
                max=a[i];
                max_idx=i;
            }
        }
    }
    // int max_count=0;
    // for (int i=0;i<l;i++) {
    //     if (a[i]==max) {
    //         max_count++;
    //     }
    // }
    // if (max_count==1) {
        printf("%d\n",max_idx);
    // }else if (max_count!=1) {
    //     printf("%d\n",min_idx);
    // }
    return 0;
}