#include <bits/stdc++.h>
using namespace std;
void fun(int n)
{
    vector <int> v(n);
    for (int i=0;i<n;i++) {
        cin >> v[i];
    }
    for (int i=n-1;i>=0;i--) {
        cout << v[i] << " ";
    }
}
int main() {
    int n;
    cin >> n;
    fun(n);    
    return 0;
}