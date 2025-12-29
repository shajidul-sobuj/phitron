#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        if (x < 4)
        {
            cout << "MILD\n";
        }
        else if (x >= 4 && x < 7)
        {
            cout << "MEDIUM\n";
        }
        else if (x >= 7)
        {
            cout << "HOT\n";
        }
    }
    return 0;
}

// MILD: If the spice level is less than
// 4
// 4.
// MEDIUM: If the spice level is greater than equal to
// 4
// 4 but less than
// 7
// 7.
// HOT: If the spice level is greater than equal to
// 7
// 7.