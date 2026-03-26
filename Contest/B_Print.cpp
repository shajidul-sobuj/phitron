#include <bits/stdc++.h>
using namespace std;
void sum(int n)
{
    int i=1;
    while (i<n) {
        cout << i << " ";
        i++;
    }
}
int main() {
    int x;
    cin >> x;
    sum(x);
    cout << x << endl;
    return 0;
}