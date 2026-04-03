#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    if (t2 < t1 && t3 >= t2) cout << ":)\n";
    else if (t2 > t1 && t3 <= t2) cout << ":(\n";
    else if (t2 > t1 && t3 > t2) {
        if ((t3-t2) < (t2-t1)) cout << ":(\n";
        else cout << ":)\n";
    }
    else if (t2 < t1 && t3 < t2) {
        if ((t2-t3) < (t1-t2)) cout << ":)\n";
        else cout << ":(\n";
    }
    else if (t1 == t2) {
        if (t3 > t2) cout << ":)\n";
        else cout << ":(\n";
    }
    return 0;
}