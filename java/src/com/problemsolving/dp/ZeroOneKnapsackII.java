package com.problemsolving.dp;

public class ZeroOneKnapsackII {
    public int solve(int[] A, int[] B, int C) {
        int n = A.length;
        int maxVal = 50 * n;
        int[] dp = new int[maxVal + 1];
        for (int i = 0; i <= maxVal; i++)
            dp[i] = 1000001;
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int val = maxVal; val >= A[i]; val--) {
                dp[val] = Math.min(dp[val], B[i] + dp[val - A[i]]);
            }
        }
        int ans = 0;
        for (int val = maxVal; val >= 0; val--) {
            if (dp[val] <= C) {
                ans = val;
                break;
            }
        }
        return ans;
    }
}
