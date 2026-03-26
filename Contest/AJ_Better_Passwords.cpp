#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[10001];
    cin >> s;
    int sz = strlen(s);
    cout << char(toupper(s[0]));
    for (int i=1;i<sz;i++) {
        if (s[i]=='s') {
            cout << "$";
        }else if (s[i]=='i') {
            cout << "!";
        }else if (s[i]=='o') {
            cout << "()";
        }else {
            cout << s[i];
        }
    }
    cout << "." << endl;
 
    return 0;
}

// Make the first character an uppercase
// Replace all s with $
// Replace all i with !
// Replace all o with ()
// Append a . (period) at the end of the password