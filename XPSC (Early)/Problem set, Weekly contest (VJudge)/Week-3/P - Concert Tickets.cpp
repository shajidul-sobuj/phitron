#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    multiset<int> st;
    for (int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }

    for (int i=0;i<m;i++)
    {
        int x;
        cin >> x;
        auto it = st.upper_bound(x);
        
        if (it == st.begin()) {
            cout << -1 << endl;
            continue;
        }
        else
        {
            it--;
            cout << *it << endl;
            st.erase(it);
        }
        
        
    }

    return 0;
}