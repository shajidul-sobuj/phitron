#include <stdio.h>

typedef struct students
{
    char name[50];
    int id;
}std;

int main()
{
    std a;
    a.id = 50;
    printf("%d\n",a.id);
    return 0;
}