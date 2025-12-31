// Solution2.cpp
// Problem: Accumulator Apex
//
// Short Problem Statement:
// We are given an initial value x and k lists.
// From any list, we can take elements only from the left,
// adding them to x as long as x never becomes negative.
// Our goal is to maximize x.
//
// Approach:
// For each list, compute all valid prefixes:
//   - prefix sum
//   - minimum prefix sum
// A prefix is usable if (x + min_prefix >= 0).
// Repeatedly select the prefix with the maximum gain.
//
// Time Complexity: O(N)
// Space Complexity: O(N)
//
// Submission Link:
// https://github.com/yogesh4216/CP-Chronicles/blob/day04-accumulator/Problems/Data-structures/Day-04/sol/yogesh/Solution2.cpp

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    int k;
    cin >> x >> k;

    vector<vector<long long>> lists(k);

    for (int i = 0; i < k; i++) {
        int l;
        cin >> l;
        lists[i].resize(l);
        for (int j = 0; j < l; j++) {
            cin >> lists[i][j];
        }
    }

    vector<bool> used(k, false);

    while (true) {
        long long bestGain = 0;
        int bestIdx = -1;

        for (int i = 0; i < k; i++) {
            if (used[i]) continue;

            long long sum = 0, minPrefix = 0;
            for (long long v : lists[i]) {
                sum += v;
                minPrefix = min(minPrefix, sum);
            }

            if (x + minPrefix >= 0 && sum > bestGain) {
                bestGain = sum;
                bestIdx = i;
            }
        }

        if (bestIdx == -1)
            break;

        x += bestGain;
        used[bestIdx] = true;
    }

    cout << x << "\n";
    return 0;
}