#include <bits/stdc++.h>
using namespace std;
int main() {
    vector <int> v = {10,20,30,50};
    auto it = find(v.begin(),v.end(),50 );
    (it==v.end()) ? cout << "not fount\n" : cout << "found\n";
    return 0;
}