#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    cin.ignore();
    vector <string> a;
    while(n--)
    {
        string s;
        getline(cin, s);
        auto it = find(a.begin(),a.end(),s);
        if (it == a.end())
            a.push_back(s);
    }
    cout << a.size() << endl;
    // for (string c : a)
    // {
    //     cout << c << endl;
    // }
    return 0;
}