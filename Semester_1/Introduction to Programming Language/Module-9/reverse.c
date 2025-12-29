#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int max,min;
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++){
        min=a[0];
        if ( (a[i]<=a[i+1]) ){
            min=a[i];
        }
        max=a[0];
        if (a[i]>=a[i+1]){
            max = a[i];
        }
    }
    // int temp=max;
    // max=min;
    // min=max;
    for (int i=0;i<n;i++){
        if (a[i]==min){
            a[i]=max;
            printf("%d ",a[i]);
        }
        else if (a[i]==max){
            a[i]=min;
            printf("%d ",a[i]);
        }
        else {printf("%d ",a[i]);}
    }
    
    return 0;
}