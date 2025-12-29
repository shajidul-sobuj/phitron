#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int count =0;
        for (int i='A';i<='Z';i++) {
            int x=count;
            for (int j=0;j<n;j++) {
                if (s[j]==i){
                    count++;
                }
            }
            if (count >x) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}