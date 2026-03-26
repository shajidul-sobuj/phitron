#include <stdio.h>

int main()
{
    for (;;)
    {
        int m, n;
        scanf("%d %d", &m, &n);
        if (n != 0 && m != 0)
        {
            int a[n];
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &a[i]);
            }
            int count = 0;
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (a[i] == a[j])
                    {
                        count++;
                    }
                }
            }
            printf("%d\n", count);
        }
        else
        {
            break;
        }
    }
    return 0;
}