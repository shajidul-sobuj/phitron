#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool ok = (s == "abc");
        for (int i = 0; i < 3 && !ok; i++)
        {
            for (int j = i + 1; j < 3 && !ok; j++)
            {
                string temp = s;
                swap(temp[i], temp[j]);
                if (temp == "abc")
                {
                    ok = true;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
