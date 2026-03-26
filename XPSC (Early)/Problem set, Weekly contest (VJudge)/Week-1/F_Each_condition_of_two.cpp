#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(((n<100) && (n>9)) || ((n>-100) && (n<-9)))
    {
        if ((n%3 == 0) && (n%2 == 0))
        {
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    else{
        cout << "NO\n";
    }

    return 0;
}