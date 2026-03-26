#include <bits/stdc++.h>
using namespace std;

void pookie()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    for (char c : s)
    {
        if (st.empty())
            st.push(c);
        else if (st.top() == c)
            st.pop();
        else
            st.push(c);
    }
    if (st.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        pookie();
    }

    return 0;
}