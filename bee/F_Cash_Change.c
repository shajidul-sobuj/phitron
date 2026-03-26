#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int v500=0,v100=0,v50=0,v10=0,v5=0,v1=0;
    if (n>=500)
    {
        v500=n/500;
        n=n-v500*500;
    }
    if (n>=100)
    {
        v100=n/100;
        n=n-v100*100;
    }
    if (n>=50)
    {
        v50=n/50;
        n=n-v50*50;
    }
    if (n>=10)
    {
        v10=n/10;
        n=n-v10*10;
    }
    if (n>=5)
    {
        v5=n/5;
        n=n-v5*5;
    }
    if (n>=1)
    {
        v1=n/1;
        n=n-v1*1;
    }
    if (v1!=0)
    {
        for (int i=1; i<=v1; i++)
        {
            printf("1 ");
        }
    }
    if (v5!=0)
    {
        for (int i=1; i<=v5; i++)
        {
            printf("5 ");
        }
    }
    if (v10!=0)
    {
        for (int i=1; i<=v10; i++)
        {
            printf("10 ");
        }
    }
    if (v50!=0)
    {
        for (int i=1; i<=v50; i++)
        {
            printf("50 ");
        }
    }
    if (v100!=0)
    {
        for (int i=1; i<=v100; i++)
        {
            printf("100 ");
        }
    }
    if (v500!=0)
    {
        for (int i=1; i<=v500; i++)
        {
            printf("500 ");
        }
    }
    return 0;
}
