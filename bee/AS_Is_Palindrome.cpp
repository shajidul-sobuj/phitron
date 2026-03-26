#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[1000];
    cin.getline(s,1000);
    int sz = strlen(s);
    int flag = 1;
    for (int i=0,j=sz-1;i<j;i++,j--) {
        if (s[i]==s[j]) {
            flag =1;
        }else {
            flag=0;
            break;
        }
    }
    (flag==1) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}