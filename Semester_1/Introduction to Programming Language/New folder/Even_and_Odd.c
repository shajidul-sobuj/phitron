#include <stdio.h>
void odd_even()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    int eco=0,oco=0;
    for (int i=0;i<n;i++) {
        if (a[i]%2==0) {
            eco++;
        }else {
            oco++;
        }
    }
    printf("%d %d",eco,oco);
}
int main()
{
    odd_even();
    return 0;
}