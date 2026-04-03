#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1)
    {
        string a,b;
        cin >> a >> b;
        if (a == "0" && b == "0") break;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int ca = 0;
        int carr = 0;
        if (a.size()<=b.size())
        {
            for (int i=0;i<b.size();i++)
            {
                int na;
                if (i<a.size())
                    na = a[i]-'0';
                else 
                    na = 0;
                int nb = b[i]-'0';
                if ((na+nb+carr) > 9)
                {
                    carr = 1;
                    ca++;
                }
                else 
                {
                    carr = 0;
                }
            }
        }
        else 
        {
            for (int i=0;i<a.size();i++)
            {
                int na = a[i]-'0';
                int nb;
                if (i < b.size())
                nb = b[i]-'0';
                else 
                nb = 0;
                if ((na+nb+carr) > 9)
                {
                    carr = 1;
                    ca++;
                }
                else 
                {
                    carr = 0;
                }
            }
        }

        if (ca == 0) cout << "No carry operation.\n";
        else if (ca == 1) cout << "1 carry operation.\n";
        else  cout << ca << " carry operations.\n";
    }
    return 0;
}