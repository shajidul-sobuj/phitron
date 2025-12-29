#include <stdio.h>
#include <stdbool.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    int a[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    bool is_dia = true;
    if (r == c)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i+j!=r-1 && a[i][j] != 0)
                {
                    is_dia = false;
                }
            }
        }
        if (is_dia == true)
        {
            printf("Its a 2nd Diagonal\n");
        }
        else
        {
            printf("Its not a 2nd dioganal\n");
        }
    }
    else
    {
        printf("Its not a 2nd dioganal\n");
    }

    return 0;
}