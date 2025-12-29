#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << "-1 ";
    
    for (int i=1;i<n;i++)
    {
        int flag=0;
        for (int j=i-1;j>=0;j--)
        {
            if (a[j]>a[i])
            {
                cout << j+1 << " ";
                flag=1;
                break;
            }
        }
        if (flag==0)
        {
            cout << "-1 ";
        }
    }

    return 0;
}