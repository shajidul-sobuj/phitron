#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    // ########## way 1 to decliar 2D vector..################
    // int n,m;
    // cin >> n >> m;
    // vector<vector<int>> v(n,vector<int>(m,5));
    // for (int i=0;i<n;i++)
    // {
    //     for (int j=0;j<m;j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    

    // ########## way 2 to decliar 2D vector..################

    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i=0;i<n;i++)
    {
        int m;
        cin >> m;
        vector <int>a;
        for (int j=0;j<m;j++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        v.push_back(a);
    }

    for (int i=0;i<v.size();i++)
    {
        for (int j=0;j<v[i].size();j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}