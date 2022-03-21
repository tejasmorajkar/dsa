package com.problemsolving;

public class UnboundedKnapsack {
    public int solve(int w, int[] val, int[] wt) {
        int n = val.length;
        int[] dp = new int[w + 1];
        for (int i = 1; i <= w; i++) {
            for (int j = 0; j < n; j++) {
                if (wt[j] <= i) {
                    dp[i] = Math.max(dp[i], val[j] + dp[i - wt[j]]);
                }
            }
        }
        return dp[w];
    }
}
