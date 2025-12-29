#include <stdio.h>

char ascii()
{
    char c;
    scanf("%c",&c);
    int asci=c;
    return asci;
}

int main()
{
    char asci = ascii();
    printf("%d",asci);
    return 0;
}