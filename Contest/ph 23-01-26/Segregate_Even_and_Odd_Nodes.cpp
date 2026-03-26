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
    vector <int> even;
    vector <int> odd;
    for (int i=0;i<n;i++)
    {
        if (a[i]%2==0) {
            even.push_back(a[i]);
        }
        else if (a[i]%2!=0)
        {
            odd.push_back(a[i]);
        }
    }
    for (int i=0;i<even.size();i++)
    {
        cout << even[i] << " ";
    }
    for (int i=0;i<odd.size();i++)
    {
        cout << odd[i] << " ";
    }
    return 0;
}