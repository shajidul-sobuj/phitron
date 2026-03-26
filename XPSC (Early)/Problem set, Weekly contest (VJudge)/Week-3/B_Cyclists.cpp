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
    int n,k,p,m;
    cin >> n >> k >> p >> m;

    deque<pair<int,int>> deck;
    for(int i=1;i<=n;i++){
        int a; cin>>a;
        deck.push_back({a,i});
    }

    int win_idx = p;
    int ans = 0;

    while(true){
        int win_pos = -1;
        for(int i=0;i<(int)deck.size();i++)
            if(deck[i].second == win_idx){ 
                win_pos=i; break; 
            }

        if(win_pos < k){
            if(m < deck[win_pos].first) 
                break;
            m -= deck[win_pos].first;
            ans++;
            auto wc = deck[win_pos];
            deck.erase(deck.begin()+win_pos);
            deck.push_back(wc);
        } else {
            int best = -1;
            for(int i=0;i<k;i++)
                if(best==-1 || deck[i].first < deck[best].first) 
                    best=i;
            if(m < deck[best].first)
                break;
            m -= deck[best].first;
            auto bc = deck[best];
            deck.erase(deck.begin()+best);
            deck.push_back(bc);
        }
    }
    cout << ans << endl;
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