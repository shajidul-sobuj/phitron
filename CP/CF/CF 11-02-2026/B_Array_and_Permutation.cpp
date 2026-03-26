#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<int> pos(n + 1); 
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]] = i; 
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> skeleton;
    if (n > 0) {
        skeleton.push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i-1]) {
                skeleton.push_back(a[i]);
            }
        }
    }

    
    bool possible = true;
    for (size_t i = 0; i < skeleton.size() - 1; ++i) {
        int currentVal = skeleton[i];
        int nextVal = skeleton[i+1];

        if (pos[currentVal] > pos[nextVal]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}