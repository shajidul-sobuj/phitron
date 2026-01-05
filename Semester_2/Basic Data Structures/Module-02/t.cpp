#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i=0;i<n;i++) {
        cin >> v[i];
    }
    int idx;
    for (int i=0;i<n;i++) {
        if (v[i]==9) {
            idx = i;
            break;
        }
    }
    v.insert(v.begin()+idx,999);
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}



// try insert function
