#include <stdio.h>
int main()
{
	int n,x;
	scanf("%d",&n);
	int a[n];
	if (n>0 && n<=100000 && x>0) {
		for (int i=0; i<n; i++) {
		        scanf("%d",&a[i]);
		}
        scanf("%d",&x);
        for (int i=0; i<n; i++) {
            if (a[i]==x){
                printf("%d ",i);
                break;
            }else if (a[i]!=x && i==n-1){
                printf("-1");
            }
        }
	}
    

	return 0;
}




// Problem Link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/B