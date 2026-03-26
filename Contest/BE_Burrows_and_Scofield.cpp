#include <bits/stdc++.h>
using namespace std;
int main() {
    char a[1001];
    char b[1001];
    cin >> a >>b;
    int sza = strlen(a);
    int szb = strlen(b);
    int suma=0;
    int sumb=0;
    for (int i=0;i<sza;i++) {
        if (a[i] >='0' && a[i]<='9') {
            suma = suma + a[i] - '0';
        }
    }
    for (int i=0;i<szb;i++) {
        if (b[i] >='0' && b[i]<='9') {
            sumb = sumb + b[i] - '0';
        }
    }
    int arr[3];
    arr[0] = suma+sumb;
    (suma>sumb) ? arr[1] = suma-sumb : arr[1] = sumb-suma;
    arr[2] = suma*sumb;
    for (int i=0;i<3-1;i++) {
        for (int j=i+1;j<3;j++) {
            if (arr[i]>arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    char c = '"';
    cout << c << arr[1] << c << endl;

    return 0;
}