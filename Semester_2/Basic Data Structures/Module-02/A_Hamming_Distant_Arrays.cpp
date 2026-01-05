#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

// Fast exponentiation (a^b mod MOD)
long long modpow(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int M = N * N;

    // Precompute factorials and inverse factorials
    vector<long long> fact(M + 1), invfact(M + 1);
    fact[0] = 1;
    for (int i = 1; i <= M; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invfact[M] = modpow(fact[M], MOD - 2);
    for (int i = M; i > 0; i--)
        invfact[i - 1] = invfact[i] * i % MOD;

    auto comb = [&](int n, int r) -> long long {
        if (r < 0 || r > n) return 0;
        return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
    };

    // Compute A = sum_{k=N+1}^{N^2} C(N^2, k) * (N-1)^(N^2-k)
    long long A = 0;
    for (int k = N + 1; k <= M; k++) {
        long long ways = comb(M, k);
        long long rest = modpow(N - 1, M - k);
        A = (A + ways * rest) % MOD;
    }

    long long total = modpow(N, 1LL * N * N * N);  // N^(N^3)
    long long bad = modpow(N, N * N) * modpow(A, N) % MOD;

    long long ans = (total - bad + MOD) % MOD;
    cout << ans << "\n";

    return 0;
}
