#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    if (s=="Like") {
        cout << "(y)";
    }else if (s=="Love") {
        cout << "<3";
    }else if (s=="Care") {
        cout << "^_<3_^";
    }else if (s=="Haha") {
        cout << ":p";
    }else if (s=="Wow") {
        cout << ":O";
    }else if (s=="Sad") {
        cout << ":'(";
    }else if (s=="Angry") {
        cout << ">_<";
    }

    return 0;
}

// Like as (y)
// Love as <3
// Care as ^_<3_^
// Haha as :p
// Wow as :O
// Sad as :'(
// Angry as >_<