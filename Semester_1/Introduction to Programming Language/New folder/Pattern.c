#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int star1=1;
    int space1=n-1;
    int temp;

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=space1;j++) {
            printf(" ");
        }
        for (int j=1;j<=star1;j++) {
            if (i%2!=0) {
                printf("#");
            }else {
                printf("-");
            }
        }
        printf("\n");
        star1+=2;
        space1--;
        temp=star1;
    }
    int star2=temp-4;
    int space2=1;
    for (int i=1;i<=n-1;i++) {
        for (int j=1;j<=space2;j++) {
            printf(" ");
        }
        for (int j=1;j<=star2;j++) {
            if (n%2!=0) {
                if (i%2!=0) {
                    printf("-");
                }else {
                    printf("#");
                }
            }else {
                if (i%2!=0) {
                    printf("#");
                }else {
                    printf("-");
                }
            }
        }
        printf("\n");
        star2=star2-2;
        space2++;
    }

    return 0;
}