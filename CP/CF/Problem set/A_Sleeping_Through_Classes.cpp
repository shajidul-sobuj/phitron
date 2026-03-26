#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin >> n >> k;
    string v;
    cin >> v;
    int test = 0;
    int count = 0;
    for (int i=0;i<n;i++)
    {
        if (v[i] == '0' && test == 0 )
        {
            count++;
        }else if (v[i] == '1')
        {
            test = k;
        }else if (v[i] == '0' && test != 0 )
        {
            test--;
        }
    }
    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}