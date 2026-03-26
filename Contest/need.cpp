#include <bits/stdc++.h>
using namespace std;
int main() {
    char c='"';
    for (int i='a';i<='z';i++) {
        cout << "else if ("  << (char)i << ">=1) {" << endl;
        cout << "       cout << " << c  << (char)i << c << " << " << (char)i  << " " << "<< endl;" << endl;
        cout << "   }" << endl;

       
    }
 
    return 0;
}
// if (a>=1) {
//        cout << "a " << a; endl;
//    }