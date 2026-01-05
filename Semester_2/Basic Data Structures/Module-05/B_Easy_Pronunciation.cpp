#include <bits/stdc++.h>
using namespace std;
bool is(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u');
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        int count = 0;
        bool hard = false;

        for (char c : s)
        {
            if (is(c))
            {
                count = 0;
            }
            else
            {
                count++;
                if (count >= 4)
                {
                    hard = true;
                    break;
                }
            }
        }
        if (hard)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}