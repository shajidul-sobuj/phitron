#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int g=1;g<=t;g++) {
        char s[1001];
        cin.getline(s,1001);
        int sz = strlen(s);
        cout << "Case #" << t << ":\n";
        for (int i=0;i<sz-1;i++) {
            int count = 0;
            for (int j=0;j<sz;j++) {
                if (s[i]==s[j] && (s[i-1] !=s[i])) {
                    count++;
                }
            }
            cout << s[i] << " " << count << endl;
        }
    }

    return 0;
}