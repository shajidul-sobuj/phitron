#include <stdio.h>
int main()
{
	int n,i;
	int x,j,f=1;
	scanf("%d",&n);
	if (n>0 && n<=15){
        for (i=1; i<=n; i++) {
		scanf("%d",&x);
        if (x>0 && x<=20)
		for (j=1; j<=x; j++) {
			f=f*j;
		}
		printf("%d\n",f);
	}
    }
	return 0;
}