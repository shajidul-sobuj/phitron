#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<long long int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];

    sort(a.begin(),a.end(),greater<long long int>());

    vector<long long int> even;
    vector<long long int> odd;
    for (long long int x : a) {
        if (x%2==0) even.push_back(x);
        else odd.push_back(x);
    }
    long long int ans=-1;
    if (even.size()==1)
    {
        ans = max(ans,even[0]);
    }else if (even.size()>=2)
    {
        ans = max(ans, max(even[0],(even[0]+even[1])));
    }
    if (odd.size()>=2)
    {
        ans = max(ans, (odd[0]+odd[1]));
    }
    cout << ans << endl;
    return 0;
}
