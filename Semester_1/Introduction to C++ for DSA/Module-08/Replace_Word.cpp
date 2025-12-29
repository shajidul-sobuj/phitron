#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s,x;
        cin >> s >> x;
        for (;;) {
            int idx=s.find(x);
            if (idx==string::npos) {
                    break;
                }
            s.replace(idx,x.size(),"#");
        }
        cout << s << endl;
    }
    return 0;
}
