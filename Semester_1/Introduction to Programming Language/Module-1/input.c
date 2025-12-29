#include<stdio.h>

int main()
{
    int a;
    float f;
    char c;
    scanf("%d", &a);
    scanf("%f", &f);
    scanf(" %c", &c);
    printf("Hello %d\n", a);
    printf("Hello %.2f\n", f);
    printf("Hello %c\n", c);
    return 0;
}