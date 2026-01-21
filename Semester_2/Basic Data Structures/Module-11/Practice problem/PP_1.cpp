#include <bits/stdc++.h>
using namespace std;

int main() {
    stack <int> st1;
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        st1.push(x);
    }
    stack <int> st2;
    int m;
    cin >> m;
    while(m--)
    {
        int x;
        cin >> x;
        st2.push(x);
    }
    if (st1.size()!=st2.size())
    {
        cout << "NO\n";
        return 0;
    }
    while(!st1.empty())
    {
        if (st1.top()!=st2.top())
        {
            cout << "NO\n";
            return 0;
        }
        st1.pop();
        st2.pop();
    }
    cout << "YES\n";

    return 0;
}