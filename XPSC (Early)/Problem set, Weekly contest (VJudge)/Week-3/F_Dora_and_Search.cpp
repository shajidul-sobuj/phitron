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

void boom()
{
    int n;
    cin >> n;

    vector<int> a(n);
    forr(i,0,n)
        cin >> a[i];
    set<int> st;
    for (int i=0;i<n;i++)
    {
        st.insert(a[i]);
    }
    int i=0,j=n-1;
    while(i<j)
    {
        if (a[i] == *st.begin() || a[i] == *st.rbegin())
        {
            st.erase(a[i]);
            i++;
            continue;
        }
        if (a[j] == *st.begin() || a[j] == *st.rbegin())
        {
            st.erase(a[j]);
            j--;
            continue;
        }

        break;
    }

    if (i<j)
        cout << i+1 << " " << j+1 << endl;
    else
        cout << -1 << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        boom();
    }

    return 0;
}