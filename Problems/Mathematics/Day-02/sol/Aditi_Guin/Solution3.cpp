#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // Step 1: Compute phi using sieve
    vector<long long> phi(N + 1);
    for (int i = 1; i <= N; i++) phi[i] = i;

    for (int i = 2; i <= N; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= N; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }

    // Step 2: Compute F(n) = sum_{d|n} d * phi(n/d)
    vector<long long> F(N + 1, 0);
    for (int d = 1; d <= N; d++) {
        for (int multiple = d; multiple <= N; multiple += d) {
            F[multiple] += d * phi[multiple / d];
        }
    }

    // Step 3: Compute final answer
    long long ans = 0;

    for (int g = 1; g <= N; g++) {
        long long sum = 0;
        for (int k = 1; g * k <= N; k++) {
            sum = (sum + F[g * k] * phi[k]) % MOD;
        }
        ans = (ans + g * (sum % MOD) % MOD * (sum % MOD)) % MOD;
    }

    cout << ans << "\n";
    return 0;
}
