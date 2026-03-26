#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[1005];
    cin.getline(s,1005);
    int sz = strlen(s);
    int countA=0;
    int counta=0;
    for (int i=0;i<=sz;i++) {
        if (s[i]>='a' && s[i]<='z') {
            counta++;
        }else if (s[i]>='A' && s[i]<='Z') {
            countA++;
        }
    }
    cout << countA << " " << counta << endl;
    return 0;
}