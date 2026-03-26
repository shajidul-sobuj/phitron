#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        long long int h;
        cin >> n >> m >> h;
        vector <int> v(n);
        vector <int> a(n);
        for (int i=0;i<n;i++) {
            cin >> v[i];
            a[i] = v[i];
        }
        while(m--)
        {
            int x;
            long long int y;
            cin >> x >> y;
            a[x-1] = a[x-1] + y;
            if (a[x-1] > h) {
                a = v;
            }
        }
        for (int p : a)
        {
            cout << p << " ";
        }
        cout << endl;
        
    }
    return 0;
}