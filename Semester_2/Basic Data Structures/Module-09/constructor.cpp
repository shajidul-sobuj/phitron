#include <bits/stdc++.h>
using namespace std;

int main() {
    list <int> l;                      // a empty list
    list <int> l(10);                 // a list with 10 size;
    list <int> l(10,3);              // a list with 10 size and the values are 3
    list <int> l = {10,20,30};      // a list and valus are 10,20,30 and so size is 3
    
    for (int x : l)
    {
        cout << x << " ";         // range based loop for print the list;
    }
    return 0;
}