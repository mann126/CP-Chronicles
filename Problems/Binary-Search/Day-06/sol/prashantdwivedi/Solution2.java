// -------------------- Problem --------------------
/*
Rudolf looks at snowflakes and imagines building one using a graph.

Start with a single vertex.
Connect it to k new vertices (k must be greater than 1).
After that, every vertex that has only one connection grows k more vertices.
This growing step must happen at least once.

Given a number n, we need to check whether it’s possible to end up
with exactly n vertices using some value of k.
*/

// -------------------- What’s actually going on --------------------
/*
After each growth step, the total number of vertices becomes:

1 + k + k^2 + k^3 + ... + k^d

So the problem is just checking whether n can be written like this
for some k >= 2 and d >= 2.
*/

// -------------------- Main idea --------------------
/*
Trying every k directly is too slow, especially in Java.

But the number of growth layers (d) is small.
Even with k = 2, values blow past 10^18 after about 60 layers.

So we loop over all possible depths d (from 2 to ~60),
and for each depth we binary search the value of k.
*/

// -------------------- How the checking works --------------------
/*
For a fixed d:
- Pick a k using binary search
- Compute 1 + k + k^2 + ... + k^d carefully
- Stop early if the value becomes too big or overflows

If we ever hit exactly n, we print YES.
Otherwise, after all tries, we print NO.
*/

// -------------------- Complexity --------------------
/*
For each test case:
- We try at most 60 values of d
- For each d, we do a binary search on k

Time complexity: O(60 * log n)
Space complexity: O(1)
*/

// -------------------- Submission --------------------
/*
https://codeforces.com/contest/1846/submission/356040210
*/

// -------------------- Code -------------------------

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution2 {

    static final long LIMIT = (long) 1e18;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        StringBuilder out = new StringBuilder();

        while (t-- > 0) {
            long n = Long.parseLong(br.readLine().trim());
            out.append(canMakeSnowflake(n) ? "YES\n" : "NO\n");
        }

        System.out.print(out.toString());
    }

    static boolean canMakeSnowflake(long n) {
        for (int d = 2; d <= 60; d++) {
            long left = 2;
            long right = (long) Math.pow(n, 1.0 / d) + 1;

            while (left <= right) {
                long mid = (left + right) >>> 1;
                long value = calcSum(mid, d);

                if (value == n) return true;
                if (value < 0 || value > n) right = mid - 1;
                else left = mid + 1;
            }
        }
        return false;
    }

    static long calcSum(long k, int d) {
        long sum = 1;
        long cur = 1;

        for (int i = 1; i <= d; i++) {
            if (cur > LIMIT / k) return -1;
            cur *= k;
            if (sum > LIMIT - cur) return -1;
            sum += cur;
        }

        return sum;
    }
}
