#include <bits/stdc++.h>
using namespace std;
int main() {
    float n;
    cin >> n;
    if (n >= 0.0 && n <= 100.00)
    {
        int m = n;
        int d = m / 10;
        int plus;
        int dot;
        plus = d;
        dot = 10 - d;
        cout << "[";
        for (int i = 0; i < plus; i++)
        {
           cout << "+";
        }
        for (int i = 0; i < dot; i++)
        {
            cout << ".";
        }
        cout << "]" << " " << m << "%" << endl;
    }

    return 0;
}