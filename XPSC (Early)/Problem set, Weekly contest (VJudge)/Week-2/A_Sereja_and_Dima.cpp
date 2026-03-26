#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    list <int> a;
    for (int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int s = 0,d = 0;
    bool t_s = true;
    while(!a.empty())
    {
        if (t_s)
        {
            s += max(a.front(),a.back());
            if (a.front()>=a.back())
                a.pop_front();
            else
                a.pop_back();
        }
        else
        {
            d += max(a.front(),a.back());
            if (a.front()>=a.back())
                a.pop_front();
            else
                a.pop_back();
        }
        t_s = !t_s;
    }
    cout << s << " " << d;
    return 0;
}