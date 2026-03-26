#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef __int128_t int128;

bool solve_case() {
    ll p_in, q_in;
    if (!(cin >> p_in >> q_in)) return false;

    int128 p = p_in;
    int128 q = q_in;
    int128 V = 3 * p - 2 * q;

    if (V == 0) return true; 

    int128 P_lim = p;
    int128 Q_lim = q - 1;
    
    int128 End = p + q - 1;

    vector<int128> points;
    points.push_back(0);        
    points.push_back(End);      
    
    int128 k1 = 2 * P_lim;
    int128 k2 = 2 * Q_lim;
    
    for (int128 k : {k1, k2}) {
        if (k >= 0 && k <= End) points.push_back(k);
    }
    
    auto check = [&](int128 k) -> bool {
        if (k <= 0 || k > End) return false;
        
        int128 val = V + 2 * k;
        if (val % 5 != 0) return false;

        int128 k_A = (k + 1) / 2; 
        int128 k_B = k / 2;       

        if (V > 0) {
            int128 a_req = val / 5;
            
            int128 bob_contribution = (k_B < P_lim) ? k_B : P_lim;
            
            int128 alice_shortage = k_A - Q_lim;
            int128 alice_forced_contribution = (alice_shortage > 0) ? alice_shortage : 0;
            
            int128 a_forced = bob_contribution + alice_forced_contribution;
            
            return a_forced >= a_req;
        } else {
            int128 num = 3 * k - V;
            int128 b_req = num / 5;
            
            int128 bob_contribution = (k_B < Q_lim) ? k_B : Q_lim;
            
            int128 alice_shortage = k_A - P_lim;
            int128 alice_forced_contribution = (alice_shortage > 0) ? alice_shortage : 0;
            
            int128 b_forced = bob_contribution + alice_forced_contribution;
            
            return b_forced >= b_req;
        }
    };

    ll rem_long = (ll)((2 * (V % 5)) % 5);
    if (rem_long < 0) rem_long += 5;
    int128 rem = rem_long;

    vector<int128> candidates;
    
    auto add_near = [&](int128 x) {
        if (x < 0) return;
        int128 r = x % 5;
        int128 down = x - r + rem;
        if (down > x) down -= 5;
        if (down >= 1 && down <= End) candidates.push_back(down);
        
        int128 up = down + 5;
        if (up >= 1 && up <= End) candidates.push_back(up);
    };

    add_near(5); 

    for (auto p : points) {
        add_near(p);
    }
    
    for (auto k : candidates) {
        if (check(k)) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            if (solve_case()) cout << "Bob\n";
            else cout << "Alice\n";
        }
    }
    return 0;
}