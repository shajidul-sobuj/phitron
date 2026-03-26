#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l = 1, r = n;
        vector <int> v(n);
        bool turn = false;

        for (int i = n - 1; i >= 0; i--)
        {
            if (!turn)
            {
                v[i] = l++;
            }
            else
            {
                v[i] = r--;
            }
            turn = !turn;
        }

        for (int i = 0; i < n-1; i++)
        {
            cout << v[i] << " ";
        }
        cout << v[n-1] << endl;
    }
    return 0;
}