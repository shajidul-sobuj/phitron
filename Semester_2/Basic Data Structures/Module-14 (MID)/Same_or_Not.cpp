#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n,m;
    cin >> n >> m;
    if (n!=m)
    {
        cout << "NO\n";
        return 0;
    }
    stack <int> st;
    queue <int> q;
    while(n--)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    while(m--)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    while(!st.empty())
    {
        if (st.top()!=q.front())
        {
            cout << "NO\n";
            return 0;
        }
        st.pop();
        q.pop();
    }
    cout << "YES\n";
    return 0;
}