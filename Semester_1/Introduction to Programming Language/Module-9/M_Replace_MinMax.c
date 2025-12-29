#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];

    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int min,max;
    min=100000;
    max=-100000;
    for (int i=0;i<n;i++){
        if (a[i]<min){
            min=a[i];
        }if(a[i]>max){
            max=a[i];
        }
    }
    // int temp;
    // temp=max;
    // max=min;
    // min=temp;
    for (int i=0;i<n;i++){
        if (a[i]==min){
            printf("%d ",max);
        }else if(a[i]==max){
            printf("%d ",min);
        }else{
            printf("%d ",a[i]);
        }
        
    } 
    
    
    return 0;
}



// problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/M