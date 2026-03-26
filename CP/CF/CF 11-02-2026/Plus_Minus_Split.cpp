#include <bits/stdc++.h>
using namespace std;

void pookie()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    bool equal = true;
    for (int i=0;i<n;i++)
    {
        if (equal && a[0]==a[i])
        {

        }else if (equal && a[0]==a[i])
        {
            equal = false;
            break;
        }
    }
    if (equal)
    {
        cout << "Yes\n";
        return;
    }

    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        pookie();
    }
    return 0;
}