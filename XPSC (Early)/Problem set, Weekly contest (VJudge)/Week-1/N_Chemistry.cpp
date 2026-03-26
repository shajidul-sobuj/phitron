#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> fr(26,0);
    for (int i=0;i<n;i++)
    {
        int idx = (int)s[i]-'a';
        fr[idx]++;
    }

    vector <int> real;
    for (int i=0;i<26;i++)
    {
        if (fr[i]!=0) 
            real.push_back(fr[i]);     
    }
    int odd_count = 0;
    int even_count = 0;
    for (int x : real)
    {
        if (x%2==0) even_count++;
        else odd_count++;
    }
    odd_count = odd_count-k;
    if(odd_count<=1)
    {
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}