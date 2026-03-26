#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;

    vector<int> s;
    auto it = find(s.begin(),s.end(),a);
    if (it == s.end()) s.push_back(a);
    it = find(s.begin(),s.end(),b);
    if (it == s.end()) s.push_back(b);
    it = find(s.begin(),s.end(),c);
    if (it == s.end()) s.push_back(c);

    cout << s.size() << endl;

    return 0;
}