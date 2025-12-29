#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);

	int a[n];

	if (n>=2 && n<=1000) {
		for (int i=0; i<n; i++) {
			scanf("%d",&a[i]);
            if (a[i]>-100000 && a[i]<100000){
                    if (a[i]<=10) {
                    printf("A[%d] = %d\n", i, a[i]);
                }
            }
		}
	}
	return 0;
}

// Problem Link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/D