#include <stdio.h>
#include <math.h>
int main()
{
    float n;
    scanf("%f", &n);
    if (n >= 0.0 && n <= 100.00)
    {
        int m = floor(n);
        int d = m / 10;
        int plus;
        int dot;
        plus = d;
        dot = 10 - d;
        printf("[");
        for (int i = 0; i < plus; i++)
        {
            printf("+");
        }
        for (int i = 0; i < dot; i++)
        {
            printf(".");
        }
        printf("] %d%%", m);
    }
    return 0;
}