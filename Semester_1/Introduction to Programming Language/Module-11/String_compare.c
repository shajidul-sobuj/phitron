#include <stdio.h>
#include <string.h>
int main()
{
    char a[101];
    char b[101];
    scanf("%s %s",&a,&b);
    for (int i=0; ;i++){
        if (a[i]=='\0' && b[i]=='\0'){
            printf("Both are same");
            break;
        }else if (a[i]=='\0' && b[i]=='\0'){
            printf("Both are same");
            break;
        }else if (a[i]=='\0'){
            printf("A is small");
            break;
        }else if (b[i]=='\0'){
            printf("B is small");
            break;
        }else if (a[i]<b[i]){
            printf("A is small");
            break;
        }else if (a[i]>b[i]){
            printf("B is small");
            break;
        }else if (a[i]==b[i]){
            continue;
        }
    }
    return 0;
}
