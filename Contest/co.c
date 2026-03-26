#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int color[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0)
        {
            color[i] = 0;
        }
        else
        {
            color[i] = 1;
        }
    }
    int bag[n];
    int x = -1;
    for (int i = 0; i < n; i++)
    {
        if (x == -1)
        {
            bag[++x] = color[i];
        }
        else if (bag[x] != color[i])
        {
            bag[++x] = color[i];
        }
        else
        {
            x--;
        }
    }
    printf("%d\n", x + 1);
    return 0;
}