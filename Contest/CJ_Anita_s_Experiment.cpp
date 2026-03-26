#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int g=1;g<=t;g++) {
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        int gd=0;
        for (int i=0;i<n;i++) {
            if (a[i]<=a[i+1] && i!=n-1) {
                gd++;
            }else if (a[i]>=a[i+1] && i!=n-1) {
                gd--;
            }else if (a[i]=a[i+1] && i!=n-1) {
                gd=1;
            }else {
                gd=0;
            }
            if (gd==0) {
                break;
            }
        }
        for (int i=0;i<n;i++) {
            if (a[i]>=a[i+1] && i!=n-1) {
                gd--;
            }else {
                gd=0;
            }
            if (gd==0) {
                break;
            }
        }
        for (int i=0;i<n;i++) {
            if (a[i]=a[i+1] && i!=n-1) {
                gd=1;
            }else {
                gd=0;
            }
            if (gd==0) {
                break;
            }
        }

        if (gd==1) {
            cout << "neutral\n";
        }else if(gd>1) {
            cout << "allGoodDays\n";
        }else if(gd<1) {
            cout << "allBadDays\n";
        }else if(gd==0) {
            cout << "none\n";
        }
    }
    return 0;
}




#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    if (N>19) {
        printf("0000\n");
        return 0;
    }
    long long fact = 1;

    for (int i = 1; i <= N; i++) {
        fact *= i;
        fact=fact%10000;
    }
    printf("%lld\n", fact);

    return 0;
}