#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        long long int n, k;
        scanf("%lld %lld", &n, &k);

        long long int steps = 0;
        while (n > 0)
        {
            if (k > n)
            {
                steps += n;
                n = 0;
            }
            else if (n % k == 0)
            {
                n /= k;
                steps++;
            }
            else
            {
                long long int remainder = n % k;
                n -= remainder;
                steps += remainder;
            }
        }

        printf("%lld\n", steps);
    }
    return 0;
}
