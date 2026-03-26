#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    if (v[0]!=v[v.size()-1])
    {
        cout << v[0]+v[v.size()-1] << endl;
    }else{
        cout << v[0] << endl;
    }
    return 0;
}