package com.problemsolving.dp;

import java.util.*;

public class ObsessiveStrings {
    private static int mod = (int) 1e9 + 7;
    private static int N = 100005;
    private static int[] f;
    private static long[] dp;
    private static long[] sum;

    private static void init() {
        f = new int[N];
        dp = new long[N];
        sum = new long[N];
    }

    private static void helper(String t) {
        int m = t.length();
        f[0] = 0;
        f[1] = 0;

        for (int i = 1; i < m; i++) {
            int j = f[i];

            while (j > 1 && t.charAt(i) != t.charAt(j)) j = f[j];
            if (t.charAt(i) == t.charAt(j)) f[i + 1] = j + 1;
            else f[i + 1] = j;
        }
    }

    public int solve(String s, String t) {
        init();
        helper(t);
        Arrays.fill(dp, 0);
        dp[0] = 1;
        Arrays.fill(sum, 0);
        sum[0] = 1;
        int j = 0, maxj = 0;
        int n = s.length(), m = t.length();
        for (int i = 0; i < n; i++) {
            while (j > 0 && j < m && s.charAt(i) != t.charAt(j)) j = f[j];
            if (s.charAt(i) == t.charAt(j)) j++;

            if (j == m) {
                maxj = i - m + 2;
                j = f[j];
            }
            dp[i + 1] += dp[i];
            if (maxj > 0) {
                dp[i + 1] += sum[maxj - 1];
            }
            if (dp[i + 1] > mod) dp[i + 1] -= mod;

            sum[i + 1] = sum[i] + dp[i + 1];
            if (sum[i + 1] > mod) sum[i + 1] -= mod;
        }
        return (int) ((dp[n] + mod - 1) % mod);
    }
}
