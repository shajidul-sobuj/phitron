#include <bits/stdc++.h>
using namespace std;

int n=-1;

int main() {
    list <int> l;
    int t;
    cin >> t;
    while(t--)
    {
        
        int x,v;
        cin >> x >> v;
        if (x == 0)
        {
            l.push_front(v);
            n++;
        }
        else if(x==n+1) {
            l.push_back(v);
            n++;
        }
        else if (x>0 && x<=n) {
            l.insert(next(l.begin(),x),v);
            n++;
        }
        if (x>n+1)
        {
            cout << "Invalid\n";
            continue;
        }
        
        
        for (int g : l)
        {
            cout << g << " ";
        }
        cout << endl;
        l.reverse();
        for (int g : l)
        {
            cout << g << " ";
        }
        cout << endl;
        l.reverse();
    }
    return 0;
}