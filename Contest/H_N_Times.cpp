#include <bits/stdc++.h>
using namespace std;
void fun()
{
    int n;
    char c;
    cin >> n >> c;
    while(n--) {
        cout << c << " ";
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        fun();
    }
    return 0;
}