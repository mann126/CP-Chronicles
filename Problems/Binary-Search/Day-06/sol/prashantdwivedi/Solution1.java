// -------------------- Problem --------------------
/*
There are n people in a town and each person has some gold.

The richest person suddenly finds extra gold (x coins) and adds it
to their own wealth.

A person is called unhappy if their wealth becomes strictly less than
half of the average wealth of all people.

If more than half of the people are unhappy, Robin Hood shows up.

For every test case, we need to find the minimum value of x that
makes this happen. If it can never happen, print -1.
*/

// -------------------- How this works --------------------
/*
Adding gold only increases the average, so the richest person will
never be unhappy.

The only way Robin Hood appears is when more than half of the people
fall below half of the average wealth.

So after sorting, we only care about the point where more than half
of the population crosses this limit.

That point is the person at index n/2 (0-based). If this person
becomes unhappy, then strictly more than half are unhappy.

From the inequality, we directly compute how much gold is needed.
If the value comes out negative, zero is enough.

For n = 1 or 2, it is impossible to make more than half unhappy.
*/

// -------------------- Complexity --------------------
/*
Sorting dominates the solution.
Time: O(n log n)
Space: O(n)
*/

// -------------------- Submission --------------------
/*
https://codeforces.com/contest/2014/submission/355974166
*/

// -------------------- Code -------------------------

import java.io.*;
import java.util.*;

public class Solution1 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());

            long[] a = new long[n];
            long sum = 0;

            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(st.nextToken());
                sum += a[i];
            }

            if (n <= 2) {
                sb.append("-1\n");
                continue;
            }

            Arrays.sort(a);

            int idx = n / 2;
            long x = 2L * n * a[idx] - sum + 1;

            if (x < 0) x = 0;

            sb.append(x).append('\n');
        }

        System.out.print(sb.toString());
    }
}
