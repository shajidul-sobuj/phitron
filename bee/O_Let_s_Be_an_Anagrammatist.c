#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int g = 1; g <= t; g++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &b[i]);
        }
        if (n > m)
        {
            for (int i = 0; i < m; i++)
            {
                if (a[i] == b[i])
                {
                    printf("Case %d: %d", g, a[i]);
                    break;
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] == b[i])
                {
                    printf("Case %d: %d", g, a[i]);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}