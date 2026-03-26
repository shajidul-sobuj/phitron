#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long w;
    cin >> n >> w;
    int a[n];
    int s[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> s[i];        
    }
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++) {
            if (s[i]<s[j]) {
                int stemp=s[i];
                s[i]=s[j];
                s[j]=stemp;
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                
            }
        }
    }
    long long sum=0;
    long long yem=0;
    for (int i = 0; i < n; ++i) {
        if (sum<w) {
            sum = sum + s[i];
            if (sum<=w) {
                yem = yem + a[i];
            }else if (sum>w) {
                break;
            }
        }  
    }

    cout << yem << endl;
    
    return 0;
}
