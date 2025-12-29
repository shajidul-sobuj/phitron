#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int count=0;
    for (int j=0;j<n;j++){
        for (int i=0;i<n;i++){
            if (j==a[i]){
                count++;
            }
        }
        if (count == 0){
            continue;
        }else {
            printf("%d -> %d\n",j,count);
        }
        
        count=0;
    }
    
    
    return 0;
}