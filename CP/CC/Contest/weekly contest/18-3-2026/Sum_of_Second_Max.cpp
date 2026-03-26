#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;

    void init(int _n) {
        n = _n;
        tree.assign(4*_n + 5, 0);
    }

    void update(int node, int s, int e, int i, int v) {
        if (s == e) { tree[node] = v; return; }
        int m = (s + e) / 2;
        if (i <= m) update(2*node, s, m, i, v);
        else update(2*node+1, m+1, e, i, v);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
    void update(int i, int v) { update(1, 1, n, i, v); }

    // [l,r] এ সবচেয়ে ডানের position যেখানে value > thr
    int rightmost(int node, int s, int e, int l, int r, int thr) {
        if (r < s || e < l || tree[node] <= thr) return 0;
        if (s == e) return s;
        int m = (s + e) / 2;
        int res = rightmost(2*node+1, m+1, e, l, r, thr);
        if (res) return res;
        return rightmost(2*node, s, m, l, r, thr);
    }
    int rightmost(int l, int r, int thr) {
        if (l > r) return 0;
        return rightmost(1, 1, n, l, r, thr);
    }

    // [l,r] এ সবচেয়ে বামের position যেখানে value > thr
    int leftmost(int node, int s, int e, int l, int r, int thr) {
        if (r < s || e < l || tree[node] <= thr) return n+1;
        if (s == e) return s;
        int m = (s + e) / 2;
        int res = leftmost(2*node, s, m, l, r, thr);
        if (res <= n) return res;
        return leftmost(2*node+1, m+1, e, l, r, thr);
    }
    int leftmost(int l, int r, int thr) {
        if (l > r) return n+1;
        return leftmost(1, 1, n, l, r, thr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n+2);
        for (int i = 1; i <= n; i++) cin >> a[i];

        // L1, L2 বের করো (বাম থেকে ডানে process)
        SegTree st;
        st.init(n);
        vector<int> L1(n+2, 0), L2(n+2, 0);
        for (int i = 1; i <= n; i++) {
            L1[i] = st.rightmost(1, i-1, a[i]);
            L2[i] = (L1[i] > 0) ? st.rightmost(1, L1[i]-1, a[i]) : 0;
            st.update(i, a[i]);
        }

        // R1, R2 বের করো (সব value tree তে আছে, query করো)
        SegTree st2;
        st2.init(n);
        for (int i = 1; i <= n; i++) st2.update(i, a[i]);

        vector<int> R1(n+2, n+1), R2(n+2, n+1);
        for (int i = 1; i <= n; i++) {
            R1[i] = st2.leftmost(i+1, n, a[i]);
            R2[i] = (R1[i] <= n) ? st2.leftmost(R1[i]+1, n, a[i]) : n+1;
        }

        // প্রতিটা element এর contribution যোগ করো
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            long long cnt = (long long)(L1[i] - L2[i]) * (R1[i] - i)
                          + (long long)(i - L1[i]) * (R2[i] - R1[i]);
            ans += (long long)a[i] * cnt;
        }

        cout << ans << "\n";
    }
    return 0;
}