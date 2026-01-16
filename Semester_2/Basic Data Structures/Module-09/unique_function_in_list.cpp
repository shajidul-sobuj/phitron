#include <bits/stdc++.h>
using namespace std;

int main() {
    list <int> l = {10, 20, 20, 20,30,40,90, 6, 99, 50};
    l.sort();                // for assending order
    // l.sort(greater<int>());
    l.unique();               // sort hote hobe, otherwise hobe na.....
    for (int x : l)
    {
        cout << x << " ";
    }
    return 0;
}