#include <stdio.h>
int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int a[r][c];
    for (int i=0;i<r;i++)  {
        for (int j=0;j<c;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    int co1=0;
    int co0=0;
    if (r==c) {
        for (int i=0;i<r;i++)  {
            for (int j=0;j<c;j++) {
                if (i==j && a[i][j]==1) {
                    co1++;
                }else if (i==j && a[i][j]!=1) {
                    break;
                }else if (i+j==r-1 && a[i][j]==1) {
                    co1++;
                }else if (i!=j && i+j!=r-1 && a[i][j]==0) {
                    co0++;
                }else if (i!=j && i+j!=r-1 && a[i][j]!=0) {
                    break;
                }else {
                    break;
                }
            }
        }
    }
    int ck1=r+c-1;
    int ck0=(r*c)-ck1;
    if (co1>=ck1 && co0<=ck0 && r%2==0) {
        printf("YES\n");
    }else if (co1==ck1 && co0==ck0 && r%2!=0) {
        printf("YES\n");
    }else {
        printf("NO\n");
    }
    return 0;
}