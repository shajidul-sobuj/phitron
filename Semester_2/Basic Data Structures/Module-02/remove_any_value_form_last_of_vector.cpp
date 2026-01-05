#include <bits/stdc++.h>
using namespace std;
int main() {
    vector <int> v = {1,2,3,4,5};        // size of this vector is 5
    v.pop_back();                       // size of this vector is 4
    v.pop_back();                      // size of this vector is 3
    for (int x : v){
        cout << x << endl;
    }
    return 0;
}