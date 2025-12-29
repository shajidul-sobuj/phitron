#include <stdio.h>
#include <string.h>

int main()
{
    char n[50];
    scanf("%s", n); 
    if(strcmp(n, "CSE") == 0) {
        printf("***একটা ডিপার্টমেন্টে পড়ি পড়ি\n");
    } else if(strcmp(n, "NFE") == 0) {
        printf("তুমি মেয়ে না, পরী\n");
    } 
    return 0;
}
