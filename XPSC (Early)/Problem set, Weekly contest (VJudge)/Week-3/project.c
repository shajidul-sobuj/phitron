#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void add_data()
{

}

int main()
{
    printf("Choose an option: \n");
    printf("1. Add a weather Data\n");
    printf("2. Remove Weather Data\n");
    printf("3. see All data \n");
    printf("4. search spacifiq time weather\n");
    printf("0. Exit\n");
    
    while(1)
    {
        int action;
        scanf("%d",&action);
        if (action == 0)
        {
            return 0;
        }
    }
}