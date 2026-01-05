#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (int i=0;i<n;i++){
            cin >> v[i];
        }
        vector<bool> bad( n, false);
        for (int i=1;i<n;i++){
            if (v[i]!= v[i-1]){
                bad[i]=true;
                bad[i-1]=true;
            }
        }
        int count=0;
        for (bool x : bad){
            if (x) count++;
        }
        cout << count << endl;
    }

    return 0;
}