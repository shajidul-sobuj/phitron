#include <stdio.h>
int main()
{
    char a[51];
    int count=0,n;
    scanf("%s",&a);
    for (int i=0;a[i]!='\0';i++){
        count++;
    }
    printf("%d",count);


    // for (int i=0;i<51;i++){
    //     n=a[i];
    //     if(n==0){
    //         printf("%d",i);
    //         break;
    //     }
    // }
}


