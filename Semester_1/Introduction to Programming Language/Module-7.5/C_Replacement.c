#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	if (n>=2 && n<=1000) {
		int a[n];
		for (int i=0; i<n; i++) {
			scanf("%d",&a[i]);
		}
		for (int i=0; i<n; i++) {
			if (a[i]>0) {
				printf("1 ");
			} else if (a[i]<0) {
				printf("2 ");
			} else {
				printf("0 ");
			}

		}

	}

	return 0;
}



// Problem Link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/C