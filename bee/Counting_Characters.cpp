#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'

#define forr(i,a,b) for(int i=a;i<b;i++)
#define forb(i,a,b) for(int i=a;i>=b;i--)

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void yes() { cout << "YES\n"; }
void no()  { cout << "NO\n";  }

// void boom()
// {
//     string large;
//     int mx = 0;
//     while(1)
//     {
//         string s;
//         getline(cin, s);
//         if (s == "0")
//         {
//             break;
//         }
//         vector<int> a;
//         string ck;
//         int count = 0;
//         for (int i=0;i<sz(s);i++)
//         {
//             if (s[i] != ' ') 
//             {
//                 count++;
//                 ck.pb(s[i]);
//             }
//             else {
//                 a.push_back(count);
//                 if (count >= mx)
//                 {
//                     mx = count;
//                     large.clear();
//                     large = ck;
//                     ck.clear();
//                 }
//                 count = 0;
//             }
//         }
//         a.push_back(count);
//         if (count >= mx)
//             {
//                 mx = count;
//                 large.clear();
//                 large = ck;
//                 ck.clear();
//             }

//         for (int i=0;i<sz(a);i++)
//         {
//             cout << a[i];
//             (i == sz(a)-1) ? cout << "" : cout << "-";
//         }
//         cout << endl;
//     }

//     cout << endl <<  "The biggest word: " << large << endl;

// }

void boom()
{
    string large;
    int mx = 0;

    while (true)
    {
        string s;
        getline(cin, s);
        if (s == "0") break;

        stringstream ss(s);
        string word;
        vector<int> a;

        while (ss >> word)
        {
            a.push_back(word.size());
            if ((int)word.size() >= mx) // last word wins in tie
            {
                mx = word.size();
                large = word;
            }
        }

        for (int i = 0; i < a.size(); i++)
        {
            if (i) cout << "-";
            cout << a[i];
        }
        cout << endl;
    }

    cout << endl << "The biggest word: " << large << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        boom();
    }

    return 0;
}