#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <long long int> a(n);
    vector <long long int> b(n);
    for (long long int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for (long long int i=0;i<n;i++)
    {
        for (long long int j=0;j<a[i];j++)
        {
            b[i] += pow((10),j);
        }
    }
    long long int count = 0;
    for (long long int x : b)
    {
        count+=x;
    }
    cout << count << endl;
    return 0;
}