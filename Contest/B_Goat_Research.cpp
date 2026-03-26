#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    char a[n];
    int szi[n];
    int mx = -100000000;
    for (int i=0;i<n;i++) {
        char s[1001];
        cin >> s;
        int sz = strlen(s);
        a[i]=s[sz];
        szi[i]=sz;
        mx = std :: max(mx,sz);
    }
    if (mx%2==0 && mx!=2) {
        mx = mx-1;
    }
    for (int j=0;j<n;j++) {
        int sz = szi[j];
        
        if (sz%2==0 && sz!=2) {
            sz = sz-1;
        }else if (sz<=2) {
            sz = sz+1;
        }
        int space = (mx-sz)/2;
        for (int k=1;k<=space;k++) {
            cout << " ";
        }
        cout << "b";
        for (int k=1;k<sz;k++) {
            cout << "a";
        }
        cout << endl;
    }

    
    

    return 0;
}