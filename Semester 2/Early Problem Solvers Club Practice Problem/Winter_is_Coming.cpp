/*
        __________________
        |                |
        |    KzSobuj     |
        |________________|

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n,a,b;
        cin >> n >> a >> b;
        vector <int> v(n);
        for (int i=0;i<n;i++) cin >> v[i];
        bool jk = false;
        int count=0;
        for (int i=0;i<n;i++)
        {
            if (v[i]<a)
            {
                if (jk == false)
                {
                    jk = true;
                    count++;
                }
            }else if (v[i]>b)
            {
                if (jk == true)
                {
                    jk = false;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}