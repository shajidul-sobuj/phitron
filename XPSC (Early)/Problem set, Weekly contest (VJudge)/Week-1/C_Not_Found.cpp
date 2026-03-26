#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector <int> fr(26,0);
    for (int i=0;i<s.size();i++)
    {
        int idx = (int)s[i]-'a';
        fr[idx]++;
    }
    for (int i=0;i<26;i++)
    {
        int x = fr[i];
        if (x == 0)
        {
            cout << (char)(i+'a') << endl;
            return 0;
        }
    }
    cout << "None\n";
    return 0;
}