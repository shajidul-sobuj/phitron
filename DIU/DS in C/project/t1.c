#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int temperature;
    int humditi;
    char date[30];
    char
} Node;

void n1()
{

}

int main()
{
    while(1)
    {
        printf("1. Input Waither Data\n");
        printf("2. Show All Data\n");
        printf("3. Edit any Data\n");
        printf("0. Exit\n");
        printf("Chose any option: \n");
        int n;
        scanf("%d",&n);
        if (n == 0)
        {
            break;
        }
        else if (n == 1)
        {
            n1();
        }
    }
}