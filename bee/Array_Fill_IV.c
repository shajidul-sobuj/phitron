#include <stdio.h>

int main()
{
    int n=15;
    int a[n];
    int x=5;
    int par1[x];
    int par2[x];
    int par3[x];
    int impar1[x];
    int impar2[x];
    int impar3[x];

    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<x;i++) {
        par1[i]=0;
        par2[i]=0;
        par3[i]=0;
        impar1[i]=0;
        impar2[i]=0;
        impar3[i]=0;
    }
    // for (int i=0;i<n;i++) {
    //     if (a[i]%2==0){
    //         // printf("%d\n",a[i]);
    //         for (int j=0;j<x;j++) {
    //             par1[j]=a[i];
    //         }
            // for (int k=i,j=0;k<15,j<5;k++,j++) {
            //     par[j]=arr[i];
            //     arr[k]=arr[k-1];
            // }
        // }else {
            // for (int k=i;k<15;k++) {
            //     arr[k]=arr[k-1];
            // }
    //     }
    // }

    for (int i=0,j=0;i<n,j<x;i++,j++) {
        if (a[i]%2==0 && par1[j]==0){
                par1[j]=a[i];
            }
        }




    for (int j=0;j<x;j++) {
        printf("%d\n",par1[j]);
    }


    // for (int i=0;i<n;i++) {
    //     printf("%d\n",a[i]);
    // }
    return 0;
}