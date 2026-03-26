#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <char> st;
    vector <char> redo;
    while(n--)
    {
        string s;
        cin >> s ;
        if (s=="TYPE")
        {
            char c;
            cin >> c;
            st.push_back(c);
            redo.clear();
        }else if (s=="UNDO")
        {
            if (!st.empty()) {
            redo.push_back(st.back());
            st.pop_back();
        }
        }else if (s=="REDO")
        {
            if (!redo.empty()) {
                st.push_back(redo.back());
                redo.pop_back();
            }
        }
    }
    for (char c : st)
    {
        cout << c;
    }
    cout << endl;
    return 0;
}