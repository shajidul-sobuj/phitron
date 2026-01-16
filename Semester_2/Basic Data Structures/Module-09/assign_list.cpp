#include <bits/stdc++.h>
using namespace std;

int main() {
    list <int> l = {1,2,3,4,5,6};
    list <int> l2;
    // l2 = l;
    l2.assign(l.begin(),l.end());
    for (int x : l2)
    {
        cout << x << " ";
    }
    return 0;
}