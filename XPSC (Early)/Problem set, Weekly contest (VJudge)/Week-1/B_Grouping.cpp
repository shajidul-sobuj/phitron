#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y;
    cin >> x >> y;
    
    vector<int> a = {1,3,5,7,10,12};
    vector<int> b = {4,6,9,11};

    vector<int> ck(13);
    for (int t : a)
    {
        ck[t]=0;
    }
    for (int t : b)
    {
        ck[t]=1;
    }
    ck[2]=-1;

    if (ck[x] == ck[y])
    {
        cout << "Yes\n";
    }
    else cout << "No\n";

    return 0;
}