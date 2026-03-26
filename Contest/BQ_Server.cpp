#include <bits/stdc++.h>
using namespace std;

int main() {
    long long h;
    cin >> h;

    long long day;
    if (h % 24 == 0)
        day = h / 24;
    else
        day = h / 24 + 1;

    cout << day << "\n";
    return 0;
}
