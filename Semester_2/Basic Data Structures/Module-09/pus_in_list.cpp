#include <bits/stdc++.h>
using namespace std;

int main() {
    list <int> l = {1,2,3,4,5,6};
    
    l.push_back(200);
    l.push_front(100);
    for (int x : l)
    {
        cout << x << " ";
    }
    return 0;
}