#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long int sum1=0;
        for (int i=0;i<3;i++) {
            sum1+=s[i];
        }
        long long int sum2=0;
        for (int i=3;i<6;i++) {
            sum2+=s[i];
        }
        bool is = (sum1==sum2);
        cout << (is ? "YES\n" : "NO\n");
    }

    return 0;
}