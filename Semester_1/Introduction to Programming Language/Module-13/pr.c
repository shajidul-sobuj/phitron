#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int max1=-1000000000,max2=-1000000000;
    int b[n];
    for (int i=0;i<n;i++){
        if (a[i]>max1 && a[i]>max2){
            max1=a[i];
            if (max2<max1){
                max2=max1;
            }
        }
    }
    printf("%d",max2);
    
    return 0;
}