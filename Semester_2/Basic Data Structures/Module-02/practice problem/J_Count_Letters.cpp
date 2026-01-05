#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    vector <char> v;
    for (char c : s) {
        auto it = find (v.begin(),v.end(),c);
        if (it == v.end()) {
            v.push_back(c);
        }
    }
    sort(v.begin(),v.end());
    for (char c : v){
        int count = 0;
        for (char l : s) {
            if (l==c) count++;
        }
        cout << c << " : " << count << endl;
    }

    return 0;
}