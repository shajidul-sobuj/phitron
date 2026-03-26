#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        long long int n,m;
        cin >> n >> m;
        vector <long long int> T(n);
        vector <long long int> J(m);
        for (long long int i=0;i<n;i++) cin >> T[i];
        for (long long int i=0;i<m;i++) cin >> J[i];
        long long int s;
        cin >> s;
        long long int count = 0;
        for (long long int i=0;i<n;i++)
        {
            for (long long int j=0;j<m;j++)
            {
                if(T[i]+J[j]==s)
                {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}