#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<bool> used(n, false);
    
    // Step 1: Specific Matching (Round)
    // Find max valid subsequence of '(' and ')'
    {
        stack<int> st;
        for(int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    used[st.top()] = true;
                    used[i] = true;
                    st.pop();
                }
            }
        }
    }
    
    // Step 2: Specific Matching (Square)
    // Find max valid subsequence of '[' and ']' on unused chars
    {
        stack<int> st;
        for(int i = 0; i < n; ++i) {
            if (used[i]) continue;
            
            if (s[i] == '[') {
                st.push(i);
            } else if (s[i] == ']') {
                if (!st.empty()) {
                    used[st.top()] = true;
                    used[i] = true;
                    st.pop();
                }
            }
        }
    }
    
    // Step 3: Generic Matching (Open vs Close)
    // On unused chars, match Any Open with Any Close
    int generic_pairs = 0;
    {
        stack<int> st; // Stores indices of Opens
        for(int i = 0; i < n; ++i) {
            if (used[i]) continue;
            
            bool is_open = (s[i] == '(' || s[i] == '[');
            
            if (is_open) {
                st.push(i);
            } else {
                // It is a close bracket
                if (!st.empty()) {
                    // Match!
                    used[st.top()] = true;
                    used[i] = true;
                    st.pop();
                    generic_pairs++;
                }
            }
        }
    }
    
    // Step 4: Count leftovers
    int rem_open = 0;
    int rem_close = 0;
    for(int i = 0; i < n; ++i) {
        if (used[i]) continue;
        if (s[i] == '(' || s[i] == '[') rem_open++;
        else rem_close++;
    }
    
    // Calculate final cost
    // Base cost is n.
    // Specific matches saved 2 per pair. (We marked them as used, so they contribute 0 to the 'remaining' cost calculation if we viewed it that way, but let's stick to the subtraction logic).
    // Actually, simpler:
    // Cost = (Number of used chars in Step 1&2 * 0) + (generic_pairs * 1) + (leftover_pairs * 1) + (bad_pairs * 2)
    // Let's invert:
    // Answer = n - (Savings)
    // Used in Step 1/2: Savings 2 per pair. Count of such pairs is (count(used) - 2*generic_pairs) / 2.
    // Generic pairs: Savings 1 per pair.
    // Leftover same-type pairs: Savings 1 per pair.
    
    int used_specific_count = 0;
    for(int i=0; i<n; ++i) if(used[i]) used_specific_count++;
    used_specific_count -= (generic_pairs * 2); // Remove generic ones from this count
    
    int savings = 0;
    savings += used_specific_count; // 2 * pairs = count
    savings += generic_pairs;       // 1 * pairs
    savings += (rem_open / 2);      // 1 * pairs
    savings += (rem_close / 2);     // 1 * pairs
    
    cout << n - savings << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}