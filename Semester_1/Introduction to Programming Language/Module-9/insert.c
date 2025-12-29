#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1]; // insert korle extra ekta value asbe ei jonno dan pashe extra wkta slot niyar jonno [n+1] deoya
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        // 
    }
    int idx,val;
    scanf("%d %d",&idx, &val);
    for (int i=n+1;i>idx;i--){
        a[i]=a[i-1];
    }
    for (int i=0;i<=n;i++){
        if (i==idx){
            a[i]=val;
            printf("%d ",a[i]);
            
        }else{
            printf("%d ",a[i]);
        }
        
    }
    
    
    return 0;
}