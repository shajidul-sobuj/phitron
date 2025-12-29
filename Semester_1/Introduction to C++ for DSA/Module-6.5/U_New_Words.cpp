#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int sz = s.size();
    int co_e=0;
    int co_g=0;
    int co_y=0;
    int co_p=0;
    int co_t=0;
    for (int i=0;i<sz;i++) {
        if (s[i]=='e' || s[i]=='E') {
            co_e++;
        }else if (s[i]=='g' || s[i]=='G') {
            co_g++;
        }else if (s[i]=='y' || s[i]=='Y') {
            co_y++;
        }else if (s[i]=='p' || s[i]=='P') {
            co_p++;
        }else if (s[i]=='t' || s[i]=='T') {
            co_t++;
        }
    }
    cout << min(co_e,(min(co_g,min(co_y,min(co_p,co_t))))) << endl;
    return 0;
}






// EGYPT