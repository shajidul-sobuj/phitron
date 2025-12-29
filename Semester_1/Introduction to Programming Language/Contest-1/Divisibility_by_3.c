#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    int arr[n];
    for (int i=0;i<n;i++){
        arr[i]=s[i]-'0';
    }
    int sum=0;
    for (int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    if (sum%3==0){
        printf("YES");
    }else {
        printf("NO");
    }
    




    return 0;
}
