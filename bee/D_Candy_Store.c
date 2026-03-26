#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int g=1;g<=t;g++) {
        int a,b;
        scanf("%d %d",&a,&b);
        int p1;
        int p2=0;
        int total;
        if (b<=a) {
            p1=b*1;
        }else if (b>a) {
            p1=a*1;
            p2 = (b-a)*2;
        }
        total=p1+p2;
        printf("%d\n",total);
    }
    return 0;
}