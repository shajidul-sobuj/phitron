#include <bits/stdc++.h>
using namespace std;

static const long long NEG = -1e18;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(M + 1, NEG));
    long long ans = 0;

    for (int i = 1; i <= N; i++) {
        vector<long long> best(M + 1, NEG);

        // Gather best from last K towns
        for (int x = max(1, i - K); x < i; x++) {
            for (int c = 0; c <= M; c++) {
                best[c] = max(best[c], dp[x][c]);
            }
        }

        // Start fresh at town i
        if (B[i] <= M) {
            dp[i][B[i]] = A[i];
            ans = max(ans, A[i]);
        }

        // Extend previous sequences
        for (int c = 0; c + B[i] <= M; c++) {
            if (best[c] == NEG) continue;
            dp[i][c + B[i]] = max(dp[i][c + B[i]], best[c] + A[i]);
            ans = max(ans, dp[i][c + B[i]]);
        }
    }

    cout << ans << endl;
    return 0;
}
