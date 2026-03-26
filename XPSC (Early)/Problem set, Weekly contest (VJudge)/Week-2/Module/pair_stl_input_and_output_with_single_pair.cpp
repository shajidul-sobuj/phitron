#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pair<string, int> student = {"Sobuj",212};
    // cout << student.first << " " << student.second << endl;    // normal Printing
    auto [name, id] = student;     // new way
    cout << name << " " << id << endl;
    return 0;
}



