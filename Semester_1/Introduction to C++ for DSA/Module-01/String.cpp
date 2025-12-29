#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    char s[1001];
    cin >> x;
    cin.ignore();  //  Enter ke ignore korar jonno
    cin.getline(s,1001);  // fgets er moto string space soho input er jonno
    cout << x << endl << s << endl;


    return 0;
}