#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 3;
    int count = 0;
    while(1)
    {
        if (n == 0) break;
        string s;
        cin >> s;
        if (s == "caw")
        {
            string t;
            cin >> t;
            cout << count << endl;
            count = 0;
            n--;
        }
        else 
        {
            if (s == "***") count += 7;
            else if (s == "**-") count += 6;
            else if (s == "*-*") count += 5;
            else if (s == "-**") count += 3;
            else if (s == "--*") count += 1;
            else if (s == "-*-") count += 2;
            else if (s == "*--") count += 4;
        }
    }
    return 0;
}