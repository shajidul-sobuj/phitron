#include <bits/stdc++.h>
using namespace std;

int not_zer()
{
    
}

int main() {
    string s;
    cin >> s;
    vector <int> fr(26);
    for (char c : s)
    {
        int x = c-'A';
        fr[x]++;
    }
    int count_odd = 0;
    vector<int> real;
    int idx;
    for (int i=0;i<26;i++)
    {
        if (fr[i]%2!=0) {
            count_odd++;
            idx = i;
        }
        if (fr[i]>0) real.push_back(fr[i]);
    }
    if (count_odd>1){
        cout << "NO SOLUTION\n";
        return 0;
    }
    if (s.size()%2!=0) s[s.size()/2]=(char)fr[idx]+'A';
    
    return 0;
}