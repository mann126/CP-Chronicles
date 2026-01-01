#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    map<vector<pair<int,int>>, long long> freq;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        // Factorize x
        map<int, int> mp;
        for (int p = 2; p * p <= x; p++) {
            while (x % p == 0) {
                mp[p]++;
                x /= p;
            }
        }
        if (x > 1) mp[x]++;

        // Reduce powers modulo k
        vector<pair<int,int>> cur, need;
        for (auto [prime, cnt] : mp) {
            int r = cnt % k;
            if (r != 0) {
                cur.push_back({prime, r});
                need.push_back({prime, (k - r) % k});
            }
        }

        // Count matching complements
        ans += freq[need];

        // Store current factorization
        freq[cur]++;
    }

    cout << ans << "\n";
    return 0;
}
