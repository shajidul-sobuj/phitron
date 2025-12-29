#include <stdio.h>
int main()
{
	int n,i;
    long long int sum=0;
	scanf("%d",&n);
    int a[n];
	if (n>0 && n<=100000){
	    for (i=0;i<n;i++){
	        scanf("%d",&a[i]);
	            sum = sum + a[i];
	    }
	}
    if (sum<0){
        sum = -sum;
    }
    printf("%lld",sum);


	return 0;
}

// Problem Link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/A