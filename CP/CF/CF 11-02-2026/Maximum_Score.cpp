#include <bits/stdc++.h>
using namespace std;

void pookie()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    int idx = 0;
    int mn = INT_MAX;
    for (int i=0;i<n;i++)
    {
        if ((a[i]-b[i])<mn)
        {
            mn = (a[i]-b[i]);
            idx = i;
        }
    }
    swap(a[idx],b[idx]);
    int count = 0;
    for (int i=0;i<n;i++) count+=a[i];
    cout << count << endl;
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