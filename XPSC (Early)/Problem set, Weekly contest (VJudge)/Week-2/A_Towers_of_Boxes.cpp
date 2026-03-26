#include <iostream>

using namespace std;

void solve() {
    int n,w,d;
    cin >> n >> w >> d;
    
    int maxh = (d/w)+1;
    int mint = (n+maxh-1)/maxh;
    
    cout << mint << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) 
    {
        solve();
    }
    
    return 0;
}