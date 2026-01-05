#include <bits/stdc++.h>
using namespace std;
int main() {
    // stracture:  v.inster(position,value);    // kon position e valu ta interst koret chai oi position
    // vector <int> v= {1,2,3,5};
    // v.insert(v.begin()+2,4);


    vector <int> a = {1,2,3,4};
    vector <int> v = {100,1000};
    v.insert(v.begin()+1,a.begin(),a.end());

    for (int x : v) {
        cout << x << " ";
    }
    return 0;
}