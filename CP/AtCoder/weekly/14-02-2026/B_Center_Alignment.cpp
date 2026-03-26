#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <string> s(n);
    for (int i=0;i<n;i++) cin >> s[i];
    int mx_length = INT_MIN;
    for (int i=0;i<n;i++)
    {
        mx_length = max(mx_length,(int)s[i].size());
    }
    for (int i=0;i<n;i++)
    {
        int x = mx_length - s[i].size();
        int left = x/2;
        int right = x-left;
        cout << string(left,'.');
        cout << s[i];
        cout << string(right,'.');
        cout << endl;
    }
    return 0;
}