#include <bits/stdc++.h>
using namespace std;
    
int N, S, L;
int M, K, P;
int R;

struct Req {
    int id;
    int ga, la, gb, lb;
};

struct Route {
    int s1, k1, m, s2, k2;
};

vector<int> oxc_state;
vector<int> oxc_map;
vector<bool> locked;

inline int get_p(int g, int s_local, int k) {
    int sp = S / P;
    return g * sp * K + (s_local % sp) * K + k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> S >> L)) return 0;
    cin >> M >> K >> P;

    int sp = S / P;
    R = N * sp * K;

    oxc_map.assign(M * R, -1);

    int Q;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);

    for (int q = 0; q < 5; ++q) {
        if (!(cin >> Q)) break;

        vector<Req> fl(Q);
        for (int i = 0; i < Q; ++i) {
            fl[i].id = i;
            cin >> fl[i].ga >> fl[i].la >> fl[i].gb >> fl[i].lb;
        }

        vector<Route> res(Q);
        vector<int> link_load(N * S * K, 0);
        locked.assign(M * R, false);

        vector<int> idx(Q);
        iota(idx.begin(), idx.end(), 0);
        shuffle(idx.begin(), idx.end(), gen);

        int mp = M / P;

        for (int i : idx) {
            const auto& f = fl[i];

            int best_load = 1e9;
            Route best_rt = {-1, -1, -1, -1, -1};
            int best_p1 = -1, best_p2 = -1;
            bool found = false;

            int tries = 60;
            for (int t = 0; t < tries; ++t) {
                int pl = gen() % P;

                int s_start = pl * sp;
                int s1 = s_start + (gen() % sp);
                int s2 = s_start + (gen() % sp);

                int k1 = gen() % K;
                int k2 = gen() % K;

                int m_local = gen() % mp;
                int m_abs = pl * mp + m_local;

                int p1 = get_p(f.ga, s1, k1);
                int p2 = get_p(f.gb, s2, k2);

                int abs_p1 = m_abs * R + p1;
                int abs_p2 = m_abs * R + p2;

                bool p1_free = !locked[abs_p1];
                bool p2_free = !locked[abs_p2];

                int conn1 = oxc_map[abs_p1];
                bool is_connected = (conn1 == p2);

                bool possible = false;
                if (is_connected) {
                    possible = true;
                } else {
                    if (p1_free && p2_free) {
                        possible = true;
                    }
                }

                if (possible) {
                    int load = link_load[f.ga * S * K + s1 * K + k1] +
                               link_load[f.gb * S * K + s2 * K + k2];

                    if (!is_connected) load += 1000;

                    if (load < best_load) {
                        best_load = load;
                        best_rt = {s1, k1, m_abs, s2, k2};
                        best_p1 = abs_p1;
                        best_p2 = abs_p2;
                        found = true;

                        if (is_connected && load < 500) break;
                    }
                }
            }

            if (found) {
                oxc_map[best_p1] = best_p2 % R;
                oxc_map[best_p2] = best_p1 % R;

                locked[best_p1] = true;
                locked[best_p2] = true;

                link_load[f.ga * S * K + best_rt.s1 * K + best_rt.k1]++;
                link_load[f.gb * S * K + best_rt.s2 * K + best_rt.k2]++;

                res[f.id] = best_rt;
            } else {
                res[f.id] = {0, 0, 0, 0, 0};
            }
        }

        for (int m = 0; m < M; ++m) {
            for (int r = 0; r < R; ++r) {
                cout << oxc_map[m * R + r] << (r == R - 1 ? "" : " ");
            }
            cout << "\n";
        }

        for (int i = 0; i < Q; ++i) {
            cout << res[i].s1 << " " << res[i].k1 << " "
                 << res[i].m << " " << res[i].s2 << " " << res[i].k2 << "\n";
        }
    }

    return 0;
}