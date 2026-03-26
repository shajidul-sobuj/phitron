#include <bits/stdc++.h>
using namespace std;

void pookie()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int idx1,idx2;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='B')
        {
            idx1 = i;
            break;
        }
    }
    for (int i=n-1;i>=0;i--)
    {
        if (s[i]=='B')
        {
            idx2 = i;
            break;
        }
    }
    //cout << idx1 << " " << idx2 << endl;
    cout << idx2-idx1+1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        pookie();
    }
    return 0;
}