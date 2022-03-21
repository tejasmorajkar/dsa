package com.problemsolving.dp;

public class ZeroOneKnapsack {
    int solve(int A[], int B[], int C) {
        int N = A.length;
        int dp[][] = new int[N + 1][C + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= C; j++) {
                if (B[i-1] <= j) {
                    dp[i][j] = Math.max(dp[i - 1][j], A[i - 1] + dp[i-1][j-B[i-1]]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[N][C];
    }
}