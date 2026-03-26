#include <bits/stdc++.h>
using namespace std;
bool is(vector <int> s)
{
    for (int i=0,j=s.size()-1;i<j;i++,j--) {
        if (s[i]!=s[j]) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    if (n%2==0) 
    {cout << "NO\n";
    return 0; }
    vector <int> s;
    // cout << s.size() << endl;
    while(n/2!=0) {
        int x;
        s.push_back(n%2);
        n=n/2;
    }
    s.push_back(n%2);
    // cout << s.size() << endl;
    // for (int c : s) {
    //     cout << c << " ";
    // }
    if (is(s)) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
    return 0;
}