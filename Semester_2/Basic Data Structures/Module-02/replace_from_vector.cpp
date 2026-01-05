#include <bits/stdc++.h>
using namespace std;
int main() {
    vector <int> v = {1,2,3,2,5,2,6,2,9};
    replace(v.begin(),v.end(),2,999);
    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}