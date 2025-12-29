#include <bits/stdc++.h>
using namespace std;
int* p;
void fun() 
{
    int *x= new int;
    cin >> *x;
    p = x;
    cout << "from Fun -> " << *p << endl;
}
int main() {
    fun();
    cout << "from Main -> " << *p << endl;

    return 0;
}


