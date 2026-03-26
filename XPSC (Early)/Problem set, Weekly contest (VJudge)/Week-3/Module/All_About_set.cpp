#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> st;
    for (int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }

    for (auto x : st)
    {
        cout << x << " ";
    }
    return 0;
}