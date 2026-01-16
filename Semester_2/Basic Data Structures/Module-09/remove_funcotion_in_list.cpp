#include <bits/stdc++.h>
using namespace std;

int main() {
    list <int> l = {10, 20, 20, 20,30,40,50};
    l.remove(20);
    for (int x : l)
    {
        cout << x << " ";
    }
    return 0;
}