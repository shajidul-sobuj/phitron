#include <bits/stdc++.h>
using namespace std;

int main() {
    list <int> l = {1,2,3,4,5,6};
    
    l.pop_back();
    l.pop_front();
    for (int x : l)
    {
        cout << x << " ";
    }
    return 0;
}