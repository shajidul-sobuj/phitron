#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int co2=0,co3=0;
    for (int i=0;i<n;i++){
        if (a[i]%2==0){
            co2++;
        }
        else if (a[i]%3==0){
            co3++;
        }else if (a[i]%2==0 && a[i]%3==0){
            co2++;
        }
    } 
    printf("%d %d",co2,co3);
    return 0;
}