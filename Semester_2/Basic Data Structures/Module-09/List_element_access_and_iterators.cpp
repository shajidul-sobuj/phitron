#include <bits/stdc++.h>
using namespace std;

int main() {
    list <int> l = {10,20,30,40,50};
    cout << l.front() << endl;     // for printing 1st element
    cout << *l.begin() <<endl;      // 1st element er iteretor return kore 
    cout << l.back() << endl;           // last elemnt return kore
    return 0;
}