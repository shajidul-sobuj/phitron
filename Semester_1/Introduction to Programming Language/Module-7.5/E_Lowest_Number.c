#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
    int low=900000;
	if (n>=2 && n<=1000) {
		for (int i=0; i<n; i++) {
			scanf("%d",&a[i]);
             if (a[i]>-100000 && a[i]<100000){
                   if (a[i]<low){
                    low = a[i];
                   }
            }
		}
	}
    for (int i=0; i<n; i++) {
        if (a[i]==low){
            printf("%d %d",a[i],i+1);
            break;
        }
    }

	return 0;
}

// Problem Link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/E