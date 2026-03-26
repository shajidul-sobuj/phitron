#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int val = 0;
    string t1 = "X++";
    string t2 = "++X";
    string t3 = "X--";
    string t4 = "--X";
    while(n--)
    {
        string s;
        cin >> s;
        if (s == t1)  
            val++;
        if (s == t2)  
            ++val;
        if (s == t3)  
            val--;
        if (s == t4)  
            --val;
    }
    cout << val << endl;
    return 0;
}