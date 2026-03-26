#include <bits/stdc++.h>
using namespace std;

void hi()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    int count=0;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
        if (a[i]==a[j]) count++;
        }
    }
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        hi();
    }
    return 0;
}