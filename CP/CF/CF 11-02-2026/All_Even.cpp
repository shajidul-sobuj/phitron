#include <bits/stdc++.h>
using namespace std;

void pookie()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    bool is_even = false;
    while(v.size()>1)
    {
        v[v.size()-2] += v[v.size()-1]; 
        v.pop_back();
        bool even = true;
        for (int i=0;i<v.size();i++)
        {
            if (v[i]%2 != 0)
            {
                even = false;
                break;
            }else{
                even = true;
            }
        }
        if (even)
        {
            is_even = true;
            break;
        }
    }
    if (v.size()==1  && v[0]%2 == 0)
    {
        cout << "Yes\n";
        return;
    }
    if (is_even)
    {
        cout << "Yes\n";
    }else{
        cout << "No\n";
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