#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    int count = 0;
    for (int i=0;i<n;i++)
    {
        bool is = false;
        for (int j=0;j<m;j++)
        {
            if (a[i][j]>0) 
                is = true;
            else 
            {
                is = false;
                break;
            }
        }
        if (is)
             count++;
    }
    cout << count << endl;
    return 0;
}