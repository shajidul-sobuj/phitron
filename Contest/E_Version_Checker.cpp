#include <bits/stdc++.h>
using namespace std;
int main() {
    char a[10001];
    char b[10001];
    cin >> a;
    cin >> b;
    int sz1=strlen(a);
    int szb = strlen(b);
    int suma1=0;
    int sumb1=0;
    for (int i=0;i<a[i]=='.';i++) {
        suma1 = suma1+a[i];
    }
    for (int i=0;i<b[i]=='.';i++) {
        sumb1 = sumb1+b[i];
    }
    if (suma1>sumb1) {
        cout << a << endl;
    }else if (suma1<sumb1){
        cout << b << endl;
    }else {

    }

    return 0;
}